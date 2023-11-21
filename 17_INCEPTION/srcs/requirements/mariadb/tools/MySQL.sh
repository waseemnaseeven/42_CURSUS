#!/bin/bash
#set -eux

service mysql start;

echo "SQL_DATABASE: ${SQL_DATABASE}"
echo "SQL_USER: ${SQL_USER}"
echo "SQL_PASSWORD: ${SQL_PASSWORD}"
echo "SQL_ROOT_PASSWORD: ${SQL_ROOT_PASSWORD}"

mysql -e "CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;"
echo -e "HERE"
mysql -e "CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'localhost' IDENTIFIED BY '${SQL_PASSWORD}';"
echo -e "HERE"
mysql -e "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
echo -e "HERE"
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"
echo -e "HERE"
mysql -e "FLUSH PRIVILEGES;"

mysqladmin -u root -p${SQL_ROOT_PASSWORD} shutdown

echo -e "HERE"

# exec mysqld_safe

echo -e "MariaDB database and user were created successfully! "