#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>

#define MAX_MESSAGE_SIZE 4096

// a corriger 

typedef struct s_client {
    int fd;
    int id;
    struct s_client *next;
} t_client;

t_client *g_clients = NULL;
int sockfd;

void fatal_msg() {
    write(2, "Fatal Error\n", strlen("Fatal Error\n"));
    exit(EXIT_FAILURE);
}

void broadcast_message(int sender_id, char *msg) {
    t_client *current = g_clients;

    while (current != NULL) {
        if (current->fd != sender_id) {
            char client_msg[MAX_MESSAGE_SIZE];
            sprintf(client_msg, "client %d: %s", sender_id, msg);
            send(current->fd, client_msg, strlen(client_msg), 0);
        }
        current = current->next;
    }
}

void add_client(int fd) {
    t_client *new_client = malloc(sizeof(t_client));
    if (new_client == NULL) {
        fatal_msg();
    }

    new_client->fd = fd;
    new_client->id = (g_clients == NULL) ? 0 : g_clients->id + 1;
    new_client->next = g_clients;
    g_clients = new_client;

    // Notify all clients about the new arrival
    char arrival_msg[MAX_MESSAGE_SIZE];
    sprintf(arrival_msg, "server: client %d just arrived\n", new_client->id);

    // while (new_client != NULL)
    // {
    //     if (new_client->fd != fd)
    //     {
    //         send(new_client->fd, arrival_msg, strlen(arrival_msg), 0);
    //     }
    //     new_client = new_client->next;
    // }
    broadcast_message(fd, arrival_msg);

}

void remove_client(int fd) {
    t_client *current = g_clients;
    t_client *prev = NULL;

    while (current != NULL) {
        if (current->fd == fd) {
            // Notify all clients about the departure
            char departure_msg[MAX_MESSAGE_SIZE];
            sprintf(departure_msg, "server: client %d just left\n", current->id);
            broadcast_message(fd, departure_msg);

            // Remove the client from the linked list
            if (prev == NULL)
                g_clients = current->next;
            else
                prev->next = current->next;

            free(current);
            break;
        }

        prev = current;
        current = current->next;
    }
}

// void print_list()
// {
//     t_client *current = g_clients;

//     while (current != NULL)
//     {
//         printf("Client ID: %d | Socket FD: %d\n", current->id, current->fd);
//         current = current->next;
//     }
// }

// void unit_test()
// {
//     print_list();
//     add_client(5);
//     add_client(6);
//     print_list();
//     remove_client(6);
//     print_list();
// }

int main(int ac, char *av[]) {
    if (ac != 2) {
        write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
        exit(0);
    }

    u_int16_t port = atoi(av[1]);

    struct sockaddr_in servaddr, cli;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fatal_msg();
    }
    // unit_test();

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    servaddr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
        fatal_msg();
    }

    if (listen(sockfd, 0) != 0) {
        fatal_msg();
    }

    fd_set read_fds, master_fds;
    FD_ZERO(&master_fds);
    FD_SET(sockfd, &master_fds);

    int max_fd = sockfd;

    while (1) {
        read_fds = master_fds;

        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) == -1) {
            fatal_msg();
        }

        for (int fd = 0; fd <= max_fd; fd++) {
            if (FD_ISSET(fd, &read_fds)) {
                if (fd == sockfd) {
                    // New connection
                    socklen_t len = sizeof(cli);
                    int connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
                    if (connfd < 0) {
                        fatal_msg();
                    }

                    // Add new client to master set
                    FD_SET(connfd, &master_fds);

                    // Update max_fd if needed
                    if (connfd > max_fd) {
                        max_fd = connfd;
                    }

                    // Add new client to the linked list
                    add_client(connfd);
                } else {
                    // Data from an existing client
                    char buffer[MAX_MESSAGE_SIZE];
                    ssize_t bytes_received = recv(fd, buffer, sizeof(buffer), 0);
                    if (bytes_received <= 0) {
                        // Client disconnected
                        remove_client(fd);

                        // Remove client from master set
                        FD_CLR(fd, &master_fds);

                        // Close the socket
                        close(fd);
                    } else {
                        // Broadcast the message to all other clients
                        buffer[bytes_received] = '\0'; // Null-terminate the received message
                        broadcast_message(fd, buffer);
                    }
                }
            }
        }
    }

    return (0);

}
