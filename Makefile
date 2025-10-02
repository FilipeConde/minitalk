
CC = cc
CFLAGS = -Wextra -Werror -Wall
TARGETS = server client

all: $(TARGETS)
	#recipe here

server: server.c
	$(CC) $(CFLAGS) -o $@ $^

client: client.c
	$(CC) $(CFLAGS) -o $@ $^

libft.a:
	make -C libft/

clean:
	rm -rf $(TARGETS)
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
# 	rm -f libftprintf.a

re: fclean all