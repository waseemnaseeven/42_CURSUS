#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

#define MAX_SIZE 4096

typedef struct s_client
{
    int fd;
    int id;
    struct s_client *next;
}               t_client;

t_client *g_client = NULL;
int sockfd = 0;

void fatal_msg()
{
    write(2, "Fatal error\n", strlen("Fatal error\n"));
    exit (1);
}

void broadcast_message(int fd, int id, char *msg)
{
    t_client *current = g_client;
    
    while (current)
    {
        if (current->fd != fd)
        {
            char send_to[MAX_SIZE];
            sprintf(send_to, "client %d: %s", id, msg);
            send(current->fd, send_to, strlen(send_to), 0);
        }
        current = current->next;
    }
}

void add_client(int fd)
{
    t_client *new_client = malloc(sizeof(t_client));
    if (new_client == NULL)
        fatal_msg();
    
    new_client->fd = fd;
    new_client->id = (g_client == NULL) ? 0 : g_client->id + 1;
    new_client->next = g_client;
    g_client = new_client;

    char arrival_msg[MAX_SIZE];
    sprintf(arrival_msg, "server: client %d just arrived\n", new_client->id);
    while (new_client)
    {
        if (new_client->fd != fd)
            send(new_client->fd, arrival_msg, strlen(arrival_msg), 0);
        new_client = new_client->next;
    }
}

void remove_client(int fd)
{
    t_client *current = g_client;
    t_client *prev = NULL;

    while (current)
    {
        if (current->fd == fd)
        {
            char departure_msg[MAX_SIZE];
            sprintf(departure_msg, "server: client %d just left\n", current->id);
            t_client *notify_clients = g_client;

            while (notify_clients)
            {
                if (notify_clients->fd != fd)
                    send(notify_clients->fd, departure_msg, strlen(departure_msg), 0);
                notify_clients = notify_clients->next;
            }

            if (prev == NULL)
                g_client = current->next;
            else
                prev->next = current->next;

            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

int main (int ac, char *av[])
{
    if (ac != 2)
    {
        write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
        exit(1);
    }

    struct sockaddr_in servaddr, cli;
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd < 0)
        fatal_msg();
    
    bzero(&servaddr, sizeof(servaddr)); 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1]));

    if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
        fatal_msg();
    
    if (listen(sockfd, 10) != 0)
        fatal_msg();
    
    fd_set read_fd, master_fd;
    FD_ZERO(&master_fd);
    FD_SET(sockfd, &master_fd);
    int max_fd = sockfd;

    while (1)
    {
        read_fd = master_fd;

        if (select(max_fd + 1, &read_fd, NULL, NULL, NULL) == -1)
            fatal_msg();
        
        for (int fd = 0; fd <= max_fd; fd++)
        {
            if (FD_ISSET(fd, &read_fd))
            {
                if (sockfd == fd)
                {
                    socklen_t len = sizeof(cli);
                    int connfd;
                    connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
                    if (connfd < 0)
                        fatal_msg();
                    
                    FD_SET(connfd, &master_fd);
                    if (connfd > max_fd)
                        max_fd = connfd;
                    
                    add_client(connfd);
                }
                else
                {
                    char buffer[MAX_SIZE];
                    ssize_t bytes = recv(fd, buffer, sizeof(buffer), 0);
                    if (bytes <= 0)
                    {
                        remove_client(fd);
                        close(fd);
                        FD_CLR(fd, &master_fd);
                    }
                    else
                    {
                        buffer[bytes] = '\0';
                        t_client *current = g_client;

                        while (current)
                        {
                            if (current->fd == fd)
                                broadcast_message(fd, current->id, buffer);
                            current = current->next;
                        }
                    }
                }
            }
        }
    }
    return 0;
}