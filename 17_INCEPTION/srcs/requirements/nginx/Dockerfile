FROM debian:buster

# Install nginx
RUN apt-get update -y && \
    apt-get install -y nginx vim curl openssl && \
    apt-get clean 

# Create SSL directory
RUN mkdir -p /etc/nginx/ssl

# Generate a self-signed SSL certificate
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/nginx.key -out /etc/nginx/ssl/nginx.crt \
    -subj "/C=US/ST=State/L=City/O=Organization/CN=localhost"

# Copy your nginx configuration
RUN mkdir -p /var/run/nginx
COPY ./nginx/conf/nginx.conf /etc/nginx/nginx.conf

# Expose ports
EXPOSE 443

# Start nginx
CMD ["nginx", "-g", "daemon off;"]