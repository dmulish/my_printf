# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmulish <dmulish@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/03 14:47:30 by dmulish           #+#    #+#              #
#    Updated: 2017/06/09 18:05:16 by dmulish          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -I includes/ -I libft/ -g

SRCS = srcs/type_d.c			\
	   srcs/type_o.c			\
	   srcs/type_s.c			\
	   srcs/type_x.c			\
	   srcs/ft_printf.c			\
	   srcs/type_big_d.c		\
	   srcs/print_flags.c		\
	   srcs/handle_modif.c		\
	   srcs/ft_itoa_long.c		\

SRCS_LIB = libft/ft_atoi.c		\
		   libft/ft_bzero.c		\
		   libft/ft_putstr.c	\
		   libft/ft_strchr.c	\
		   libft/ft_strlen.c	\
		   libft/ft_strsub.c	\
		   libft/ft_strdup.c	\
		   libft/ft_strcmp.c	\
		   libft/ft_isdigit.c	\
		   libft/ft_toupper.c	\
		   libft/ft_digitnum.c	\
		   libft/ft_memalloc.c	\
		   libft/ft_itoa_base.c	\

BINS = $(SRCS:.c=.o)

BINS_LIB = $(SRCS_LIB:.c=.o)

all: $(NAME)

$(NAME): $(BINS) $(BINS_LIB)
	make -C libft/
	ar rcu $(NAME) $(BINS) $(BINS_LIB)
	ranlib $(NAME)

%.o:%.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(BINS)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
