# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksticks <ksticks@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 20:27:05 by ksticks           #+#    #+#              #
#    Updated: 2019/09/20 14:35:50 by edrowzee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRC = \
	  src/string/ft_atoi.c \
      src/string/ft_bzero.c \
      src/string/ft_isalnum.c \
      src/string/ft_isalpha.c \
      src/string/ft_isascii.c \
      src/string/ft_isdigit.c \
      src/string/ft_isprint.c \
      src/string/ft_memalloc.c \
      src/string/ft_memccpy.c \
      src/string/ft_memchr.c \
      src/string/ft_memcmp.c \
      src/string/ft_memcpy.c \
      src/string/ft_memdel.c \
      src/string/ft_memmove.c \
      src/string/ft_memset.c \
      src/string/ft_putchar.c \
      src/string/ft_putchar_fd.c \
      src/string/ft_putendl.c \
      src/string/ft_putendl_fd.c \
      src/string/ft_putnbr.c \
      src/string/ft_putnbr_fd.c \
      src/string/ft_putstr.c \
      src/string/ft_putstr_fd.c \
      src/string/ft_strcat.c \
      src/string/ft_strchr.c \
      src/string/ft_strclr.c \
      src/string/ft_strcmp.c \
      src/string/ft_strcpy.c \
      src/string/ft_strdel.c \
      src/string/ft_strdup.c \
      src/string/ft_strequ.c \
      src/string/ft_striter.c \
      src/string/ft_striteri.c \
      src/string/ft_strjoin.c \
      src/string/ft_strlcat.c \
      src/string/ft_strlcpy.c \
      src/string/ft_strlen.c \
      src/string/ft_strmap.c \
      src/string/ft_strmapi.c \
      src/string/ft_strncat.c \
      src/string/ft_strncmp.c \
      src/string/ft_strncpy.c \
      src/string/ft_strnequ.c \
      src/string/ft_strnew.c \
      src/string/ft_strnstr.c \
      src/string/ft_strrchr.c \
      src/string/ft_strsplit.c \
      src/string/ft_strstr.c \
      src/string/ft_strsub.c \
      src/string/ft_strtrim.c \
      src/string/ft_tolower.c \
      src/string/ft_toupper.c \
      src/string/ft_strrev.c \
	  \
	  src/format/ft_itoa.c \
	  src/format/ft_ultoa.c \
	  src/format/ft_ftoa.c \
	  \
      src/list/ft_lstadd.c \
      src/list/ft_lstaddend.c \
      src/list/ft_lstdel.c \
      src/list/ft_lstdelone.c \
      src/list/ft_lstiter.c \
      src/list/ft_lstmap.c \
      src/list/ft_lstnew.c \
      \
      src/math/ft_sqrt.c \
      src/math/ft_pow.c \
      src/math/ft_abs.c \
      src/math/ft_trig.c \
      src/math/ft_log.c \
      \
	  src/linalg/matrix.c \
	  src/linalg/matrix_invert.c \
	  src/linalg/vector.c \
      \
      src/ft_realloc.c \
      src/ft_swap.c \
      src/get_next_line.c \
      src/t_buff.c \
      src/endian.c \
      \
      src/printf/conversion.c \
      src/printf/spec_parse.c \
      src/printf/ft_printf.c

OBJ = $(SRC:.c=.o)

TEST_SRC = \
      tests/tests_printf.c \
      tests/tests_math.c \
      tests/tests_main.c \
      tests/gnl.c
TEST_OBJ = $(TEST_SRC:.c=.o)

OPTION = -I.

all : $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

test.o : $(NAME) $(TEST_OBJ)
	$(CC) -o test.o $(TEST_OBJ) $(OPTION) -L . -lft -lm

test : test.o
	@./test.o

valgrind_check : test.o
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes --vgdb=no ./test.o

%.o : %.c
	$(CC) $(FLAGS) -c $(<) -o $(<:.c=.o) $(OPTION)

clean :
	/bin/rm -f $(OBJ) $(TEST_OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
