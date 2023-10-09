# FT_IRC 🧠

## HOW TO MAKE AN IRC SERVER

- init structure de données, classes, heritage, gestion d'erreur

- parsing input 1 et 2
    - input1:
        - 8080
        - 127.0.0.1
        - null ou \0
    - input2:
        - alpha num
        - caracteres speciaux acceptés
        - null ou \0 interdit

- init server

- switch case pour les commandes

### EVERYTHINGS I'VE TO KNOW

![Screenshot](img/socket.png)

- port: port sur lequel mon server se reposera sur les messages entrants (du client?)
Les ports :  les numéros de port permettent de différencier différentes services sur un même ordinateur ayant une seule adresse IP. Par exemple, si vous avez un ordinateur avec une seule adresse IP et que vous souhaitez gérer à la fois les services de messagerie entrants et les services web, vous pouvez le faire en utilisant des numéros de port différents. Différents services sur Internet ont des numéros de port bien connus. Par exemple, HTTP (pour le web) utilise le port 80, telnet utilise le port 23, SMTP (pour les e-mails) utilise le port 25, et ainsi de suite. Les ports numérotés en dessous de 1024 sont souvent considérés comme spéciaux et nécessitent généralement des privilèges spéciaux du système d'exploitation pour être utilisés.

- password:

- Le serveur doit être capable de gérer plusieurs clients en même temps sans jamais se bloquer.

- I/O operations must be non-blocking (I/O = Entrée/Sortie)
    - utilisation de fcntl() pour rendre les fd non bloquants
    - int fcntl(int s, int cmd, long arg);
    - utilisation après accept() avec cmd = F_SETFL et arg = O_NONBLOCK

- Only 1 poll() for operations like read, write, listen
    - epoll est un gestionnaire de fd

- Communication between client and server has to be done via TCP/IP v4 or v6

- IRC client reference, has to got those features:
    - authenticate: nickname, username, join channel, send and receive private messages using your reference client
    - implement the commands specific to channel operator:
        - KICK, INVITE, TOPIC, MODE

- Les clients doivent avoir le même num de port pour recevoir les messages. Le client envoie la requête au serveur qu'il souhaite envoyer à un message à une autre personne, le serveur envoie une réponse.

- Chaque user a un fd unique, le serveur doit pouvoir gérer plusieurs clients en même temps sans jamais se bloquer. On va utiliser epoll().

## FUNCTIONS AUTHORIZED:

- les `sockets` consiste a interagir avec d'autres programmes en utilisant les fd. Un fd c'est un int associe a un fichier ouvert. C'est un node, qui écoute sur un port particulier sur un IP, pendant que l'autre socket (client) rejoint le client pour se connecter. C'est lors de la connexion que l'on gère les cas d'erreur.
    - int sockfd = socket(domain, type, protocol)
        - un int en sortie, c'est le socket descriptor
        - domain : domaine communication, AF_LOCAL pour le standard POSIX communication entre les processus sur le même hôte.
        - type : SOCK_STREAM: TCP(reliable, connection oriented) ou SOCK_DGRAM: UDP(unreliable, connectionless)
        - protocol on va mettre 0
    - `close`:
    - `setsockopt`: permet de configurer les options du socket
        - int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);
        - sockfd: socket descriptor
        - level: SOL_SOCKET pour manipuler les options au niveau du socket
        - optname: SO_REUSEADDR:
        Pouvoir reutiliser une adresse IP et un port
    - `getsockname`: permet de recuperer l'adresse et le port du socket
        - int getsockname(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
        - sockfd: socket descriptor
        - addr: pointeur sur une structure sockaddr, qui contient l'adresse du socket
        - addrlen: taille de la structure sockaddr
    - `getprotobyname`: permet de recuperer le numero de protocole associe a un nom de protocole
    - `gethostbyname`: permet de recuperer les informations sur l'hote (ici c'est was-VirtualBox)
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
    - sockfd: socket descriptor
    - addr: pointeur sur une structure sockaddr, qui contient l'adresse et le port
    - addrlen: taille de la structure sockaddr
    - `connect`:
- vient du client, va connecter le socket client avec le socket server
    - int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    - `listen`:
- `listen()` va mettre le socket server en mode passif, il attend le client pour un connexion. backlog defini la longueur max a laquelle la file d'attente des connexions en attente pour sockfd peut croitre. Si une demande arrive alors que la file d'attente est pleine, le client peut recevoir une erreur (ECONNREFUSED).
    - int listen(int sockfd, int backlog);
    - sockfd: socket descriptor
    - backlog: taille de la file d'attente
    - `accept`:
Vous appelez `accept()` et vous lui dites d'obtenir la connexion en attente. Ça reviendra
à vous un tout nouveau descripteur de fichier socket à utiliser pour cette connexion unique ! C'est vrai, tout à coup tu as
deux descripteurs de fichiers socket pour le prix d'un ! L'original est toujours à l'écoute de nouvelles connexions,
et celui nouvellement créé est enfin prêt à envoyer() et recv().
    - (nouveau fd) int accept(int sockfd, adrr, adrrlen);
        - sockfd: socket server/descriptor
        - addr: pointeur sur une structure sockaddr, qui contient l'adresse du client qui se connecte
        - addrlen: taille de la structure sockaddr
    - `htons`: convertit le numero de port dans l'ordre des octets de l'hote vers l'ordre des octets du reseau, host to network short
    - `htonl`: convertit le numero de port dans l'ordre des octets de l'hote vers l'ordre des octets du reseau, host to network long
    - `ntohs, ntohl`: convertit le numero de port dans l'ordre des octets du reseau vers l'ordre des octets de l'hote, network to host short/long
    - `inet_addr`: convertit une adresse IP en notation pointee en une adresse reseau binaire
    - `inet_ntoa`: convertit une adresse reseau binaire en notation pointee
    - `send`: envoie des donnees sur un socket
    - `recv`: recoit des donnees sur un socket
    - `signal`:
    - `sigaction`:
    - `lseek`:
    - `fstat`: 
    - `fcntl`: permet de manipuler les descripteurs de fichiers
    - `poll()` ou `epoll()` ou `select()` ou `kqueue()` :
        - epoll va surveiller plusieurs fd pour voir si des evenements sont prets a etre traites. epoll_create() cree un epoll instance et retourne un fd qui peut etre utilise pour referencer l'instance. epoll_ctl() manipule les operations de l'instance epoll. epoll_wait() attend les evenements sur l'instance epoll referencée par le fd epfd. epoll_wait() retourne le nombre d'evenements prets a etre traites, ou -1 si une erreur s'est produite.
