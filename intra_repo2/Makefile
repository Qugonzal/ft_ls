# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 00:14:59 by qugonzal          #+#    #+#              #
#    Updated: 2020/02/26 17:15:04 by quegonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#     \/\/\/Colours-----

NO_COLOR = \033[0m
WAIT_COLOR = \033[1;33m
OK_COLOR = \033[1;32m
CLEAN_COLOR = \033[1;36m

#     \/\/\/Compiliation-----

NAME = ft_ls
CC = gcc -fsanitize=address
CFLAGS = -Wall -Wextra -Werror

#     \/\/\/Files-----

SRC = main.c $(addprefix ft_, $(addsuffix .c, \
	link_arg_lst inverse\
	set_options error unique_files\
	ascii_arg\
	print print_2 print_3\
	time stat max path skip\
	ls ls_l))

LIB_SRC = $(addprefix libft/ft_, $(addsuffix .c, \
	   putchar putnbr putstr putnstr strcmp strncmp strlen strstr strnstr \
	   strdup strcpy strncpy strcat strncat strlcat strchr strrchr \
	   memset bzero memcpy memccpy memmove memchr memcmp atoi isalpha \
	   isdigit isalnum isascii isprint toupper tolower memalloc \
	   memdel strnew strdel strclr striter striteri strmap strmapi \
	   strequ strnequ strsub strjoin strnjoin strtrim strsplit itoa putendl \
	   putchar_fd putstr_fd putendl_fd putnbr_fd lstnew lstdelone lstdel \
	   lstadd lstiter lstmap is_prime sqrt power putlongnbr atoli strcut))

LIB = libft/libft.a

OBJ = $(SRC:.c=.o)

#     \/\/\/Rules-----

.PHONY: all clean fclean re

all: $(NAME) 

$(NAME): Makefile $(OBJ) ft_ls.h $(LIB) libft/Makefile
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@ 
	@echo "$(OK_COLOR)	--- $(NAME) compiled ! ---	$(NO_COLOR)"

$(LIB): $(LIB_SRC) libft/libft.h
	@make all -C libft

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c $(SRC)
	@echo "$(OK_COLOR)	--- Binaries created ---	$(NO_COLOR)"

norme:
	@norminette $(SRC) $(INC)

clean:
	rm -rf $(OBJ)
	@make clean -C libft
	@echo "$(CLEAN_COLOR)	--- Binaries deleted ---		$(NO_COLOR)"
	
fclean: clean
	@make fclean -C libft
	rm -rf $(NAME)
	@echo "$(CLEAN_COLOR)	--- $(NAME) deleted ---		$(NO_COLOR)"

re: fclean all
