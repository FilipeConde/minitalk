# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/20 19:20:11 by fconde-p          #+#    #+#              #
#    Updated: 2025/08/07 16:38:03 by fconde-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_strdup.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_tolower.c \
	ft_strncmp.c \
	ft_toupper.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_bzero.c \
	ft_memset.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strnstr.c \
	ft_memcmp.c \
	ft_memchr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \

BONUS_SRC = ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c

OBJ = $(SRCS:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

CC = cc
CFLAGS = -Wextra -Werror -Wall

bonus:
	$(MAKE) OBJ="$(OBJ) $(BONUS_OBJ)" all


all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $(<) -o $(@)

clean:
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f libft.a

re: fclean all
