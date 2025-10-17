
CC = cc
CFLAGS = -Wextra -Werror -Wall
TARGETS = server client

all: $(TARGETS)

server: server.c libft/libft.a
	$(CC) $(CFLAGS) -o $@ $^ -Llibft -lft

client: client.c libft/libft.a
	$(CC) $(CFLAGS) -o $@ $^ -Llibft -lft

libft/libft.a:
	make -C libft/

clean:
	rm -rf $(TARGETS)
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean

re: fclean all