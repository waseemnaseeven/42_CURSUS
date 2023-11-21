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

### PQ DOCKER ? DIFF AVEC VM ?

Pourquoi les développeurs utilisent Docker ? 🤔

Le grand avantage de Docker est la possibilité de modéliser chaque conteneur sous la forme d'une image que l'on peut stocker localement.

🔎 Un conteneur est une machine virtuelle sans noyau.

📌 Ce que j’appelle noyau est tout l’ensemble du système permettant à la machine virtuelle de fonctionner, l’OS, le coté graphique, réseau, etc…

🔎 En d’autres termes, un conteneur ne contient que l’application et les dépendances de l’application.

💡 Une image docker c’est un dossier, il contient obligatoirement votre Dockerfile à la racine du dossier mais peut aussi contenir un tas d’autres fichiers pour ensuite pouvoir les copier directement dans votre VM.

## DOCKERFILE

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
  Vous indiquez simplement ou se trouve votre fichier à copier à partir du répertoire ou se trouve votre Dockerfile, puis la ou vous souhaitez le copier dans votre machine virtuelle. Ca utilise le protocole SSH (a verifier pcq mama conseil)

- `EXPOSE` = L'instruction EXPOSE expose le port spécifié et le rend disponible uniquement pour la communication entre conteneurs.
  EXEMPLE: Pour que l'application WordPress puisse parler au serveur MariaDB, le conteneur WordPress doit exposer le port. Jetez un œil au Dockerfile de l'image officielle de wordpress et vous verrez une ligne disant EXPOSE3306. C'est ce qui aide les deux conteneurs à communiquer l'un avec l'autre.

Ainsi, lorsque votre conteneur WordPress essaie de se connecter au port 3306 du conteneur MariaDB, c'est l'instruction EXPOSE qui rend cela possible.

- `ENTRYPOINT` = Lancer une commande avant le lancement de Docker

### DOCKER CMDS

- docker build -t /path/to/directory .
  - constuction des images
  - '-t' tags l'image
  - le '.' permet a Docker de tcheker le dockerfile dans le dossier courant

APRES UN BUILD REUSSI :

- docker image ls

  - visualiser images

- docker run -dp 127.0.0.1:3000:3000 /path/to/directory

  - '-d' pour --detach run le container
  - '-p' creer un port entre le host et le container.
  - http://localhost:3000 (pour constater le resultat)

- docker run -it <image>
  - run le container avec le terminal

LORSQUE QU'IL EST RUN :

- docker ps ou docker ps -a
  - connaitre les containers actuellement lances

LA SUPPRESSION A N'IMPORTE QUEL MOMENT:

- Pour supprimer un old container

  - docker stop <the-container-id> (ex:7da7ff2b9c80)
  - docker rm <the-container-id> (ex:7da7ff2b9c80)

- Pour supprimer une image

  - docker rmi (-f pour force)

- Pour supprimer tous les containers meme en arriere plan
  - docker system prune -af

## DOCKER COMPOSE

    - Outil qui a ete dev pour aider a definir et a partager des applications multi-conteneurs

    - Fichier YAML:

### DOCKER-COMPOSE CMDS

- docker-compose build

  - construction uniquement des images

- docker-compose up

  - build et run des images

- docker-compose ps

  - état des services

- docker-compose start

  - on redémarre les conteneurs du service

- docker-compose stop

  - arrete le processus les services

- docker-compose rm

  - supprime les services

- docker-compose scale SERVICE=3

  - lance 3 instances

- docker-compose pull
  - maj des images

## NGINX

- Un serveur web (qui stocke, traite et fournit des fichiers de sites internet) donc qui utilise le protocole HTTP

* openssl:

  - logiciel open-source qui implemente protocole de securite SSL pour assurer la securite des communications sur un reseau. Ca chiffre les donnees transmises entre un client et un serveur.
  - Securise la connexion et ajoute 'S' a HTTP : HTTPS
  - RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
     -keyout /etc/nginx/ssl/nginx.key -out /etc/nginx/ssl/nginx.crt \
     -subj "/C=US/ST=State/L=City/O=Organization/CN=localhost" - This command generates a self-signed SSL/TLS certificate and private key using the OpenSSL command-line tool. The `req` command is used to generate a new certificate signing request (CSR) and to self-sign the certificate using the provided private key. In this specific command, the `-x509` option specifies that a self-signed certificate should be generated, and the `-nodes` option specifies that the private key should not be encrypted with a passphrase. The `-out` option specifies the output file for the certificate, and the `-keyout` option specifies the output file for the private key. The `-subj` option is used to specify the subject field of a certificate signing request (CSR). The subject field contains information about the identity of the certificate's owner, such as the common name(domain name), organization name, and country.

* nginx ne comprends pas tout, il faut lui envoyer un .conf avec les requetes....

* Decortiquer le nginx.conf

- Utilisateur et ID de processus : Cela définit l'utilisateur sous lequel NGINX s'exécutera (www-data est un utilisateur courant pour les serveurs web dans de nombreuses distributions Linux) et spécifie le chemin du fichier d'ID de processus.

```Dockerfile
    user www-data;
    pid /run/nginx.pid;
```

- Configure le nombre maximal de connexions simultanées que chaque processus ouvrier peut gérer.

```Dockerfile
events {
    worker_connections 1024;
}
```

- Définit le répertoire racine du serveur et spécifie les fichiers index à rechercher.

```Dockerfile
    root /var/www/html/wordpress;
    index index.php index.html index.htm index.nginx-debian.html;
```

- Les blocs locations servent a gerer les demandes de fichiers (requetes) statiques ou fichiers PHP

- Configure les protocoles SSL et spécifie les chemins des fichiers de certificat SSL et de clé privée.

## MARIADB

    * MariaDB est un système de gestion de base de données édité sous licence GPL. Il s'agit d'un embranchement communautaire de MySQL : la gouvernance du projet est assurée par la fondation MariaDB.

    * fichier de config mySQL/Mariadb :
        - [server] : C'est le début du bloc de configuration server, ce qui indique que les options suivantes s'appliquent au serveur MariaDB/MySQL dans son ensemble.

        - [mysqld] : C'est le début du bloc de configuration mysqld, ce qui indique que les options suivantes s'appliquent spécifiquement au processus serveur MySQL/MariaDB.

        - user : Cette option spécifie le compte utilisateur sous lequel le serveur MySQL/MariaDB doit s'exécuter. Dans ce cas, la valeur est définie sur mysql.

        - port : Cette option définit le numéro de port TCP sur lequel le serveur MariaDB/MySQL écoutera les connexions clientes entrantes. Dans ce cas, la valeur est définie sur 3306, qui est le numéro de port par défaut.

        - basedir : Cette option spécifie le répertoire de base pour l'installation de MariaDB/MySQL. Dans ce cas, la valeur est définie sur /usr.

        - datadir : Cette option spécifie le répertoire où le serveur MariaDB/MySQL doit stocker ses fichiers de données. Dans ce cas, la valeur est définie sur /var/lib/mysql.

        - pid-file : Cette option spécifie l'emplacement du fichier PID pour le serveur MariaDB/MySQL. Le fichier PID est utilisé pour stocker l'ID de processus du processus serveur. Dans ce cas, la valeur est définie sur /var/run/mysqld/mysqld.pid.

        - socket : Cette option spécifie l'emplacement du fichier de socket Unix que le serveur MariaDB/MySQL doit utiliser pour les connexions locales. Dans ce cas, la valeur est définie sur /var/run/mysqld/mysqld.sock.

        - skip_networking : Cette option spécifie si le support du réseau pour le serveur doit être activé ou désactivé. Le réglage de cette option sur off signifie que le support du réseau est activé.

        - max_allowed_packet : Cette option définit la taille maximale de paquet que le serveur peut envoyer ou recevoir. Dans ce cas, la valeur est définie sur 64 mégaoctets.

        - log_error : Cette option spécifie l'emplacement du fichier journal d'erreurs pour le serveur MariaDB/MySQL. Dans ce cas, la valeur est définie sur /var/log/mysql/error.log.

## WORDPRESS
