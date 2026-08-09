FROM debian:trixie-slim
WORKDIR /my
COPY webserver.c ./
RUN apt update && apt install -y nginx gcc libfcgi-dev && \
	gcc -o fcgi_hello webserver.c -lfcgi && \
	rm -rf /var/lib/apt/lists
COPY nginx/conf.d/fcgi_hello.conf /etc/nginx/conf.d/fcgi_hello.conf
EXPOSE 81 
CMD ["sh", "-c", "nginx -g 'daemon off;' & /my/fcgi_hello"]

