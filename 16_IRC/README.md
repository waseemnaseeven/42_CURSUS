# FT_IRC 🧠

## TO_DO LIST

- message du invite vers la personne qui se fait inviter
- Verifier s'il y a encore qqun dans le channel
- Gerer le handle file transfer

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

- handle file transfer:
    - /dcc send <nickname> /filepath/
    - /dcc get 
        - chercher a l'endroit ou irssi a ete lance

## EVERYTHINGS I'VE TO KNOW

### CONNECTION SERVER-CLIENTS (MONITORING MULTIPLE FDS)

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

- Les clients doivent avoir le même num de port pour recevoir les messages. Le client envoie la requête au serveur qu'il souhaite envoyer à un message à une autre personne, le serveur envoie une réponse.

- Chaque user a un fd unique, le serveur doit pouvoir gérer plusieurs clients en même temps sans jamais se bloquer. On va utiliser epoll().

		epoll pour manipuler plusieurs clients 
		epoll_create1(EPOLL_CLOEXEC) crer un descrpteur de fichier
		CLO_EXEC indique que le descripteur sera ferme automatiquement
		lorsqu'un exec est effectue dans le processus (utile pour eviter
		les fuites de descripteur)

		Vous ajoutez le descripteur de fichier du socket serveur à 
		l'instance epoll en utilisant epoll_ctl() avec EPOLL_CTL_ADD. 
		Vous spécifiez que vous souhaitez surveiller les événements 
		EPOLLIN, ce qui signifie que l'événement sera déclenché 
		lorsqu'il y aura des données à lire sur le socket serveur.

        epoll_wait : pour attendre des événements sur les descripteurs de fichiers surveillés par epoll. Cela bloquera jusqu'à ce qu'au moins un événement se produise.

- Difference entre fcntl() et epoll_wait():
    - `fcntl` va rendre un fd (comme le socket par ex) non bloquant, ca signifie que les operations de lecture et d'ecriture sur le fd, meme s'il n'y a pas de donnees dispo pour la lecture ou si le tampon est plein pour l'ecriture. ca nous permet de ne pas manquer d'evenements avant de passer sur de la gestion asynchrone.

    - `epoll_wait` c'est de la gestion asynchrone des entrees/sorties pour les sockets.
    il va attendre et gerer les evenements sur un ensemble de fd surveille par epoll, il gere uniquement la connexion de plusieurs fd a un meme socket.

    - `Efficacité` : L'une des raisons d'utiliser epoll est de gérer efficacement de nombreuses connexions simultanées. En configurant les descripteurs de fichiers avec fcntl avant de les ajouter à epoll, vous vous assurez que chaque opération de lecture ou d'écriture ultérieure sur ces descripteurs de fichiers se comportera conformément à vos attentes en matière de blocage ou de non-blocage. Cela garantit que votre boucle de gestion des événements avec epoll_wait ne sera pas bloquée, ce qui serait le cas si vous tentiez de lire ou d'écrire sur un socket bloquant.

### CHANNEL DEVICE

- Un `channel` va comporter
    - un nom de channel
    - un ou plusieurs clients
    - channel est une string qui commence soit par & ou #, max 200 caracteres
    - un channel peut etre prive ou public
    - ne doit pas contenir d'espace (/r/n/t) ou ',' ou ':' ou 7bit ASCII
    - un channel peut etre cree par un client
    - limite de 10 channels par client

- IRC client reference, has to got those features:
    - authenticate: nickname, username, join channel, send and receive private messages using your reference client

### COMMANDS
AUTHENTICATION
- CAP LS
- PASS
- NICK
- USER
ONLY OPERATORS CAN USE THOSE COMMANDS
- KICK
    - trouver le client a kick sinon erreur
- INVITE (mode +i)
    - trouver le client a inviter sinon erreur
- TOPIC
- OPER
- MODE

### USERS

- Un client doit :
    - avoir un nickname
        - no space, no ',', no asterisk, no ?, no dot, no \0, no ':' no '$, & or #', - 


- Un user peut etre un operator 

etc...

### MESSAGES

- gestion des spams
- gestion des messages vides
- gestion des messages trop longs
- gestion des messages avec des caracteres speciaux
- FAIRE UN DEFINE DE MESSAGE

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
