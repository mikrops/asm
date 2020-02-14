# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 21:09:37 by mmonahan          #+#    #+#              #
#    Updated: 2020/02/14 19:41:24 by mmonahan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_charcount.c \
		ft_wordcount.c \
		ft_strfree.c \
		ft_intcount.c \
		ft_isupper.c \
		ft_islower.c \
		ft_isspace.c \
		ft_lstlen.c \
		ft_del.c \
		ft_map_char.c \
		ft_map_int.c \
		ft_put_map_int_fd.c \
		ft_put_map_chr_fd.c \
		ft_map_int_del.c \
		ft_map_chr_del.c \
		ft_pow.c \
		ft_atoi_base.c \
		ft_map_void.c \
		ft_map_void_del.c \
		ft_degtorad.c \
		ft_radtodeg.c \
		ft_str_rejoin.c \
		ft_strcut.c

OBJ = $(SRC:.c=.o)

HEADER = libft.h

all: $(NAME)

$(NAME):
		#компилируем файлы с расширением .о для $(NAME)
		@gcc -Wall -Wextra -Werror -c -I $(HEADER) $(SRC)
		#собираем библиотеку $(NAME)
		@ar rc $(NAME) $(OBJ)
		#посторение оглавления библиотеки для $(NAME)
		@ranlib $(NAME)

clean:
		#удаляем файлы компиляции .o для $(NAME)
		@rm -f *.o

fclean: clean
		#удаляем библиотеку $(NAME)
		@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
