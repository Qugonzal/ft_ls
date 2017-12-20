# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 00:14:59 by qugonzal          #+#    #+#              #
#    Updated: 2017/12/15 05:40:30 by qugonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#     \/\/\/Colours-----

NO_COLOR = \033[0m
WAIT_COLOR = \033[1;33m
OK_COLOR = \033[1;32m
CLEAN_COLOR = \033[1;36m

#     \/\/\/Compiliation-----

NAME = ft_ls
CC = gcc
CFLAGS = -Wall -Wextra -Werror

#     \/\/\/Files-----

SRC = main.c $(addprefix ft_, $(addsuffix .c, \
	link_arg_lst \
	options error \
	ascii_arg \
	ls))

OBJ = $(SRC:.c=.o)

INC = -I ./libft/ -L ./libft -lft

#     \/\/\/Rules-----

.PHONY: all clean fclean re

all: $(NAME) 

$(NAME): $(OBJ)
	@make all -C libft
	$(CC) $(CFLAGS) $(INC) $(OBJ) ft_ls.h -o $@ 
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
