# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmulish <dmulish@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/03 14:47:30 by dmulish           #+#    #+#              #
#    Updated: 2017/06/02 17:19:25 by dmulish          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

FLAGS = -Wall -Wextra -Werror -I includes/ -g

SRCS = srcs/type_d.c			\
	   srcs/ft_printf.c			\
	   srcs/print_flags.c		\
	   srcs/handle_modif.c		\

BINS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	make -C libft/
	gcc -o $(NAME) $(FLAGS) $(BINS) libft/libft.a

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(BINS)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
