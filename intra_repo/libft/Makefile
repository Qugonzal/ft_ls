# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quegonza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 15:06:02 by quegonza          #+#    #+#              #
#    Updated: 2020/02/21 15:39:25 by quegonza         ###   ########.fr        #
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

$(NAME): $(OBJ) ./libft.h
	@gcc -c -Wall -Wextra -Werror $(SRC)
	@ar -rc $(NAME) $(OBJ)
#	@ranlib $(NAME)

.SILENT:
	$(OBJ)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
