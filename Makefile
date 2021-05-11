# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunoh <seunoh@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 17:47:25 by seunoh            #+#    #+#              #
#    Updated: 2021/05/10 21:58:14 by seunoh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS = srcs/ft_flags.c srcs/ft_precision.c srcs/ft_print_nbr.c srcs/ft_print_str.c\
		srcs/ft_printf.c srcs/ft_width.c srcs/utils_base.c srcs/utils_join_buf.c

LIBC	= ar rc
OBJS = ${SRCS:.c=.o}
INCS	= .
CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

re:		fclean all
