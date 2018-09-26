# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apetrech <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/20 15:57:59 by apetrech          #+#    #+#              #
#    Updated: 2018/07/31 17:28:59 by apetrech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror 

LIBFT = libft

LIB = libft.a

SRCS = cases.c \
		ft_printf.c \
		ft_precwidlen.c \
		flags.c \
		ft_print_binary.c \
		ft_print_char.c \
		ft_print_hex.c \
		ft_print_nbr.c \
		ft_print_octal.c \
		ft_print_point.c \
		ft_print_str.c \
		ft_print_unbr.c \
		ft_printf.c \
		ft_wstr.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	$(CC) $(FLAGS) -c $(SRCS) -I $(LIBFT)
	ar rcs $(NAME) $(OBJS) $(LIBFT)/*.o 
	ranlib $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)/$(LIB)

re: fclean all

