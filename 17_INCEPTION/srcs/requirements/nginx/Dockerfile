FROM debian:buster

# Install nginx
RUN apt-get update -y && \
    apt-get install -y nginx vim curl openssl && \
    apt-get clean 

# Create SSL directory
RUN mkdir -p /etc/nginx/ssl

# Generate a self-signed SSL certificate
# ou inception.key et inception.crt
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/nginx.key -out /etc/nginx/ssl/nginx.crt \
    -subj "/C=US/ST=State/L=City/O=Organization/CN=localhost"

# Create nginx PID directory
RUN mkdir -p /var/run/nginx

# Copy your nginx configuration
COPY ./conf/nginx.conf /etc/nginx/nginx.conf

RUN chmod 755 /var/www/html

RUN chown -R www-data:www-data /var/www/html

# Expose ports
EXPOSE 443

# Start nginx
ENTRYPOINT ["nginx", "-g", "daemon off;"]