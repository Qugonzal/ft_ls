# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/29 10:54:35 by qugonzal          #+#    #+#              #
#    Updated: 2017/10/03 17:24:27 by qugonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =  $(addprefix ft_, $(addsuffix .c, \
	   putchar putnbr putstr putnstr strcmp strncmp strlen strstr strnstr \
	   strdup strcpy strncpy strcat strncat strlcat strchr strrchr \
	   memset bzero memcpy memccpy memmove memchr memcmp atoi isalpha \
	   isdigit isalnum isascii isprint toupper tolower memalloc \
	   memdel strnew strdel strclr striter striteri strmap strmapi \
	   strequ strnequ strsub strjoin strnjoin strtrim strsplit itoa putendl \
	   putchar_fd putstr_fd putendl_fd putnbr_fd lstnew lstdelone lstdel \
	   lstadd lstiter lstmap is_prime sqrt power putlongnbr atoli strcut))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC)
	ar -rc $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
