# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kakubo-l <kakubo-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 16:27:13 by kakubo-l          #+#    #+#              #
#    Updated: 2025/11/13 15:41:42 by kakubo-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	=	ft_atoi.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strmapi.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strtrim.c\
			ft_substr.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_printf.c \
       		ft_print_char.c \
			ft_print_string.c\
			ft_print_decimal.c\
			ft_print_unsigned.c\
			ft_print_pointer.c\
			ft_print_hex.c\
			ft_str_copy_cat.c\
			get_next_line.c\
			ft_clean_dlist.c\
			ft_create_dlist.c\
			ft_create_dnode.c\
			ft_indexof_dlist.c\
			ft_push_beg_dlist.c\
			ft_push_lst_dlist.c\
			ft_push_next_dlist.c\
			ft_push_prev_dlist.c\
			ft_remove_beg_dnode.c\
			ft_remove_dnode.c\
			ft_remove_lst_dnode.c\

			
OBJS = ${SRCS:.c=.o}
LIBC = ar rcs
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -fPIC
RM		= rm -f

all:		$(NAME)

${NAME}: ${OBJS}
	@${LIBC} ${NAME} ${OBJS}


%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@ 


clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME} 

re:	fclean all

.PHONY:		all clean fclean re