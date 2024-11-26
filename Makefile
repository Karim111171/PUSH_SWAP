# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 13:29:36 by kkeirouz          #+#    #+#              #
#    Updated: 2024/11/07 22:17:53 by kkeirouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

ARCHIVE = push_swap.a

SRCS =	ft_atoi.c \
		ft_split.c \
		push_swap.c \
		ft_count_args.c \
		ft_create_list.c \
		ft_free_argv.c \
		ft_validate_args.c \
		ft_printf.c  \
		ft_putchar.c \
		ft_putnbr.c	\
		ft_putstr.c \
		handle_format.c \
		ft_puthexa.c \
		ft_putptr.c	\
		ft_putunbr.c \
		swap_move.c \
		push_move.c \
		rotate_move.c \
		rev_rotate_move.c \
		small_sort.c \
		utils.c \
		process.c \
		handle_input.c \
		sort_five_and_more.c \
		sort_five_and_more2.c \
		utils1.c \
		utils2.c \
		utils3.c \

MAKE_LIB = ar -rcs

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 -ggdb

all: $(NAME)

$(NAME): $(ARCHIVE)
	$(CC) $(CFLAGS) $< -o $@

$(ARCHIVE) : $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $^

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(ARCHIVE)

fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
