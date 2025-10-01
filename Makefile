
CC = cc
CFLAGS = -Wextra -Werror -Wall
TARGETS = server client

all: $(TARGETS)
	#recipe here

server: server.c
	$(CC) $(CFLAGS) -o $@ $^

client: client.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(TARGETS)

fclean: clean
# 	rm -f libftprintf.a

re: fclean all