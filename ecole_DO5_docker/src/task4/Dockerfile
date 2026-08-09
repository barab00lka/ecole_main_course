FROM nginx:alpine
WORKDIR /my
COPY webserver.c ./
COPY nginx/conf.d/fcgi_hello.conf /etc/nginx/conf.d/fcgi_hello.conf
RUN apk add --no-cache gcc libc-dev fcgi-dev && gcc -o fcgi_hello webserver.c -lfcgi
EXPOSE 81 
CMD ["sh", "-c", "nginx -g 'daemon off;' & /my/fcgi_hello"]
