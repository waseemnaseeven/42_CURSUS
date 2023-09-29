# FT_IRC 🧠

## FUNCTIONS AUTHORIZED:
    - `socket`:
        int sockfd = socket(domain, type, protocol)
    - `close`:
    - `setsockopt`:
    - `getsockname`:
    - `getprotobyname`:
    - `gethostbyname`:
    - `getaddrinfo`:
    - `freeaddrinfo`: 
    - `bind`:
    - `connect`:
    - `listen`:
    - `accept`:
    - `htons`:
    - `htonl`:
    - `ntohs, ntohl`:
    - `inet_addr`:
    - `inet_ntoa`:
    - `send`:
    - `recv`:
    - `signal`:
    - `sigaction`:
    - `lseek`:
    - `fstat`:
    - `fcntl`:
    - `poll`:

## HOW TO MAKE AN IRC SERVER

- port:

- password:

- Handling multiple client at the same time and never hang

- I/O operations must be non-blocking

- Only 1 poll() for operations like read, write, listen

- Communication between client and server has to be done via TCP/IP v4 or v6

- IRC client reference, has to got those features:
    - authenticate: nickname, username, join channel, send and receive private messages using your reference client
    - implement the commands specific to channel operator:
        - KICK, INVITE, TOPIC, MODE

### EVERYTHINGS I'VE TO KNOW

- les sockets consiste a interagir avec d'autres programmes en utilisant les fd. Un fd c'est un int associe a un fichier ouvert. 

![Screenshot](img/socket.png)