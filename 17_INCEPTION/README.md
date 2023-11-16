# INCEPTION 

## WHAT IS DOCKER ?

- Crée par Solomon Hykes, un franco-americain.

- C'est une plateforme open-source qui permet de dev, déployer et exécuter des applications dans des conteneurs. Docker utilise le noyau linux ainsi que ses fonctionnalités pour séparer des processus afin qu'ils s'exécutent de manière indépendante. Cette indépendance reflète l'objectif des conteneurs : exécuter plusieurs processus et applications séparément les uns des autres afin d'optimiser l'utilisation de notre infrastructure tout en bénéficiant du même niveau de sécurité que celui des systèmes distincts.

Docker a resolu l'un des plus gros pb des dev, 
Se retrouver à créer un super programme sur son ordinateur, et se rendre compte qu’il ne fonctionne que sur son propre ordinateur. Pour l’utiliser ailleurs il va falloir installer les dépendances requises.

Les types de problèmes que corrige Docker:
- Une dépendance n’est pas compatible avec votre version de logiciel 😅
- Vous possédez déjà la dépendance mais dans une version différente 😑
- Votre dépendance n’existe pas sur votre OS 😓
- Votre dépendance crash au lancement 😮‍💨

`Docker est un outil qui peut empaqueter une application et ses dépendances dans un conteneur isolé`

![Screenshot](img/conteneur.png)

Pourquoi les développeurs utilisent Docker ? 🤔

Le grand avantage de Docker est la possibilité de modéliser chaque conteneur sous la forme d'une image que l'on peut stocker localement.

🔎 Un conteneur est une machine virtuelle sans noyau.

📌 Ce que j’appelle noyau est tout l’ensemble du système permettant à la machine virtuelle de fonctionner, l’OS, le coté graphique, réseau, etc…

🔎 En d’autres termes, un conteneur ne contient que l’application et les dépendances de l’application.

💡 Une image docker c’est un dossier, il contient obligatoirement votre Dockerfile à la racine du dossier mais peut aussi contenir un tas d’autres fichiers pour ensuite pouvoir les copier directement dans votre VM.

### DOCKERFILE 

```c
    FROM		alpine:3.12

    RUN			apk update && apk upgrade && apk add	\
                                openssl			\
                                nginx			\
                                curl			\
                                vim				\
                                sudo

    RUN			rm -f /etc/nginx/nginx.conf

    COPY		./config/nginx.conf /etc/nginx/nginx.conf
    COPY		scripts/setup_nginx.sh /setup_nginx.sh

    RUN			chmod -R +x /setup_nginx.sh

    EXPOSE		443

    ENTRYPOINT	["sh", "setup_nginx.sh"]
```

- `FROM` = Permet d’indiquer à Docker sous quel OS doit tourner ma machine virtuelle.

- `RUN` = Lance une commande sur ma VM. 
L’équivalent de se connecter en ssh, puis de taper une commande bash, comme : echo “Hello World!”, qui affichera….
En général, les premiers RUN fournit dans le Dockerfile consistent à mettre à jour les ressources de votre VM, comme apk, ou encore d’ajouter les utilitaires basiques comme vim, curl ou sudo.

- `COPY` = copier un fichier.
Vous indiquez simplement ou se trouve votre fichier à copier à partir du répertoire ou se trouve votre Dockerfile, puis la ou vous souhaitez le copier dans votre machine virtuelle.

- `EXPOSE` = L'instruction EXPOSE expose le port spécifié et le rend disponible uniquement pour la communication entre conteneurs.
EXEMPLE: Pour que l'application WordPress puisse parler au serveur MariaDB, le conteneur WordPress doit exposer le port. Jetez un œil au Dockerfile de l'image officielle de wordpress et vous verrez une ligne disant EXPOSE3306. C'est ce qui aide les deux conteneurs à communiquer l'un avec l'autre.

Ainsi, lorsque votre conteneur WordPress essaie de se connecter au port 3306 du conteneur MariaDB, c'est l'instruction EXPOSE qui rend cela possible.

- `ENTRYPOINT` = Lancer une commande avant le lancement de Docker

### DOCKER COMPOSE
    - Outil qui a ete dev pour aider a definir et a partager des applications multi-conteneurs

    - Fichier YAML:



### DOCKER CMDS

* docker build -t /path/to/directory .
    - constuction des images
    - '-t' tags l'image
    - le '.' permet a Docker de tcheker le dockerfile dans le dossier courant

* docker run -dp 127.0.0.1:3000:3000 /path/to/directory
    - '-d' pour --detach run le container 
    - '-p' creer un port entre le host et le container.
    -  http://localhost:3000 (pour constater le resultat)

* Pour supprimer un old container
    - docker ps
    - docker stop <the-container-id> (ex:7da7ff2b9c80)
    - docker rm <the-container-id> (ex:7da7ff2b9c80)


### DOCKER-COMPOSE CMDS

* docker-compose build
	- construction uniquement des images

* docker-compose up
	- build et run des images

* docker-compose ps
	- état des services

* docker-compose start
    - on redémarre les conteneurs du service

* docker-compose stop
    - arrete le processus les services

* docker-compose rm
    - supprime les services

* docker-compose scale SERVICE=3
	- lance 3 instances

* docker-compose pull
	- maj des images

### NGINX

- Un serveur web (qui stocke, traite et fournit des fichiers de sites internet) donc qui utilise le protocole HTTP

* openssl: 
    - logiciel open-source qui implemente protocole de securite SSL pour assurer la securite des communications sur un reseau. Ca chiffre les donnees transmises entre un client et un serveur.
    - Securise la connexion et ajoute 'S' a HTTP : HTTPS
    - RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
        -keyout /etc/nginx/ssl/nginx.key -out /etc/nginx/ssl/nginx.crt \
        -subj "/C=US/ST=State/L=City/O=Organization/CN=localhost"
            - This command generates a self-signed SSL/TLS certificate and private key using the OpenSSL command-line tool. The `req` command is used to generate a new certificate signing request (CSR) and to self-sign the certificate using the provided private key. In this specific command, the `-x509` option specifies that a self-signed certificate should be generated, and the `-nodes` option specifies that the private key should not be encrypted with a passphrase. The `-out` option specifies the output file for the certificate, and the `-keyout` option specifies the output file for the private key. The `-subj` option is used to specify the subject field of a certificate signing request (CSR). The subject field contains information about the identity of the certificate's owner, such as the common name(domain name), organization name, and country.


### MARIADB

### WORDPRESS