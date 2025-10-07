
CC = cc
CFLAGS = -Wextra -Werror -Wall
TARGETS = server client

all: $(TARGETS)
	#recipe here

server: server.c
	$(CC) $(CFLAGS) -o $@ $^ -L libft -lft

client: client.c
	$(CC) $(CFLAGS) -o $@ $^ -L libft -lft

libft.a:
	make -C libft/

clean:
	rm -rf $(TARGETS)
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean

re: fclean all