# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 00:14:59 by qugonzal          #+#    #+#              #
#    Updated: 2018/09/25 19:11:53 by qugonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#     \/\/\/Colours-----

NO_COLOR = \033[0m
WAIT_COLOR = \033[1;33m
OK_COLOR = \033[1;32m
CLEAN_COLOR = \033[1;36m

#     \/\/\/Compiliation-----

NAME = ft_ls
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

#     \/\/\/Files-----

SRC = main.c $(addprefix ft_, $(addsuffix .c, \
	link_arg_lst inverse\
	set_options error \
	ascii_arg \
	ls ls_l))

OBJ = $(SRC:.c=.o)

INC = -Llibft ./libft/libft.a

#     \/\/\/Rules-----

.PHONY: all clean fclean re

all: $(NAME) 

$(NAME): $(OBJ)
	@make all -C libft
	$(CC) $(CFLAGS) $(OBJ) $(INC) -o $@ 
	@echo "$(OK_COLOR)	--- Compiled ! ---	$(NO_COLOR)"

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)
	@echo "$(OK_COLOR)	--- Binary   created ---	$(NO_COLOR)"

norme:
	@norminette $(SRC) $(INC)

clean:
	rm -rf $(OBJ)
	@make clean -C libft
	@echo "$(CLEAN_COLOR)	--- Binary   deleted ---		$(NO_COLOR)"
	
fclean: clean
	@make fclean -C libft
	rm -rf $(NAME)
	@echo "$(CLEAN_COLOR)	--- Program  deleted ---		$(NO_COLOR)"

re: fclean all
