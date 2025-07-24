FROM debian:bullseye

EXPOSE 9000
EXPOSE 3306

ENV \
	WP_TITLE=$WP_TITLE \
	WP_ADMIN_USER=$WP_ADMIN_USER \
	WP_ADMIN_PASSWORD=$WP_ADMIN_PASSWORD \
	WP_ADMIN_EMAIL=$WP_ADMIN_EMAIL \
	WP_USER=$WP_USER \
	WP_PASSWORD=$WP_PASSWORD \
	WP_EMAIL=$WP_EMAIL \
	WP_LOCAL=$WP_LOCAL \
	WP_VERSION=$WP_VERSION \
	DB_HOST=$DB_HOST

# RUN curl -o tools/wait-for-it.sh https://raw.githubusercontent.com/vishnubob/wait-for-it/master/wait-for-it.sh
# RUN chmod +x tools/wait-fot-it.sh

# COPY ./tools/wordpress.sh /wordpress.sh
# RUN chmod +x wordpress.sh

RUN apt-get update -y && apt-get upgrade -y
# 													fastcgi
RUN apt-get install -y curl mariadb-client php7.4 php7.4-fpm php7.4-mysql

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
# 	add to path, run like normal command
RUN mv ./wp-cli.phar /usr/local/bin/wp

RUN mkdir -p /var/www/html
RUN chown -R www-data:www-data /var/www/html

# specify the exposed socket to connect via nginx
RUN sed -i 's/listen = \/run\/php\/php7.4-fpm.sock/listen = 9000/g' /etc/php/7.4/fpm/pool.d/www.conf

WORKDIR /var/www/html

ENTRYPOINT [ "/wp.sh" ]

CMD [ "/usr/sbin/php-fpm7.4", "-F"]