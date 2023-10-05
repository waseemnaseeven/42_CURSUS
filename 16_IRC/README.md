# FT_IRC 🧠

## HOW TO MAKE AN IRC SERVER

- port: port sur lequel mon server se reposera sur les messages entrants (du client?)

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

![Screenshot](img/socket.png)

- les ports :  les numéros de port permettent de différencier différentes services sur un même ordinateur ayant une seule adresse IP. Par exemple, si vous avez un ordinateur avec une seule adresse IP et que vous souhaitez gérer à la fois les services de messagerie entrants et les services web, vous pouvez le faire en utilisant des numéros de port différents. Différents services sur Internet ont des numéros de port bien connus. Par exemple, HTTP (pour le web) utilise le port 80, telnet utilise le port 23, SMTP (pour les e-mails) utilise le port 25, et ainsi de suite. Les ports numérotés en dessous de 1024 sont souvent considérés comme spéciaux et nécessitent généralement des privilèges spéciaux du système d'exploitation pour être utilisés.

- Les clients doivent avoir le même num de port pour recevoir les messages. Le client envoie la requête au serveur qu'il souhaite envoyer à un message à une autre personne, le serveur envoie une réponse.

- 

## FUNCTIONS AUTHORIZED:

- les `sockets` consiste a interagir avec d'autres programmes en utilisant les fd. Un fd c'est un int associe a un fichier ouvert. C'est un node, qui écoute sur un port particulier sur un IP, pendant que l'autre socket (client) rejoint le client pour se connecter. C'est lors de la connexion que l'on gère les cas d'erreur.
    - int sockfd = socket(domain, type, protocol)
        - un int en sortie, c'est le socket descriptor
        - domain : domaine communication, AF_LOCAL pour le standard POSIX communication entre les processus sur le même hôte.
        - type : SOCK_STREAM: TCP(reliable, connection oriented) ou SOCK_DGRAM: UDP(unreliable, connectionless)
        - protocol on va mettre 0
    - `close`:
    - `setsockopt`:
    - `getsockname`:
    - `getprotobyname`:
    - `gethostbyname`:

    - `getaddrinfo`:
- aide a configurer les structures nécessaires pour les opérations réseau ultérieures.
    - int getaddrinfo(const char *restrict node,
                       const char *restrict service,
                       const struct addrinfo *restrict hints,
                       struct addrinfo **restrict res);
    - The addrinfo structure used by getaddrinfo() contains the following fields:
```cpp
           struct addrinfo {
               int              ai_flags;
               int              ai_family;
               int              ai_socktype;
               int              ai_protocol;
               socklen_t        ai_addrlen;
               struct sockaddr *ai_addr;
               char            *ai_canonname;
               struct addrinfo *ai_next;
           };
```
    - `freeaddrinfo`:
    - `bind`:
- le bind() intervient après la création d'un socket, la fonction va `bind` le socket avec l'adresse et le numéro de port spécifié sur addr
    - int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

    - `connect`:
- vient du client, va connecter le socket client avec le socket server
    - int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    - `listen`:
- `listen()` va mettre le socket server en mode passif, il attend le client pour un connexion. backlog defini la longueur max a laquelle la file d'attente des connexions en attente pour sockfd peut croitre. Si une demande arrive alors que la file d'attente est pleine, le client peut recevoir une erreur (ECONNREFUSED).
    - int listen(int sockfd, int backlog);

    - `accept`:
Vous appelez `accept()` et vous lui dites d'obtenir la connexion en attente. Ça reviendra
à vous un tout nouveau descripteur de fichier socket à utiliser pour cette connexion unique ! C'est vrai, tout à coup tu as
deux descripteurs de fichiers socket pour le prix d'un ! L'original est toujours à l'écoute de nouvelles connexions,
et celui nouvellement créé est enfin prêt à envoyer() et recv().
    - (nouveau fd) int accept(int fd, adrr, adrrlen); 
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
