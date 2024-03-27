# INCEPTION

First project that introduce student to docker, docker-compose, database. It wasnt on the project but i create a Vagrant file to automate the installation of a VM. 

The purpose of this project was to deploy a wordpress website (basic one) with a database (here, mariadb) and a server (which is nginx). 

## LINUX

I made this project on a VM, on Ubuntu latest version.

## RUN THE SCRIPT

```
git clone https://github.com/waseemnaseeven/42_CURSUS.git
cd 42_CURSUS && cd 17_INCEPTION
```

If you want to install a VM, you'll need virtual box. 
then, `vagrant up`

otherwise, 

```
make all
```

it will create directories for the volume of wordpress and mariadb.

