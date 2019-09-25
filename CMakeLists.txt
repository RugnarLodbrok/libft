cmake_minimum_required(VERSION 3.6.2)
#set(CMAKE_C_COMPILER /cygdrive/s/program_files/cygwin/bin/gcc.exe CACHE PATH "" FORCE)
#set(CMAKE_CXX_COMPILER /cygdrive/s/program_files/cygwin/bin/g++.exe CACHE PATH "" FORCE)
project(libft_run C)
set(CMAKE_C_STANDARD 90)
include_directories(.)
include_directories(headers)

#--------------LIB LINK EXAMPLE---------------------
#add_executable(<exe_name> sorce1 source2)
#find_library(FT ft libft)
#target_link_libraries(<exe_name> LINK_PUBLIC ${FT})
#---------------------------------------------------

#add_library(libft.a
add_executable(libft_tests tests/tests_main.c tests/gnl.c
		src/string/ft_atoi.c
		src/string/ft_bzero.c
		src/string/ft_isalnum.c
		src/string/ft_isalpha.c
		src/string/ft_isascii.c
		src/string/ft_isdigit.c
		src/string/ft_isprint.c
		src/string/ft_memalloc.c
		src/string/ft_memccpy.c
		src/string/ft_memchr.c
		src/string/ft_memcmp.c
		src/string/ft_memcpy.c
		src/string/ft_memdel.c
		src/string/ft_memmove.c
		src/string/ft_memset.c
		src/string/ft_putchar.c
		src/string/ft_putchar_fd.c
		src/string/ft_putendl.c
		src/string/ft_putendl_fd.c
		src/string/ft_putnbr.c
		src/string/ft_putnbr_fd.c
		src/string/ft_putstr.c
		src/string/ft_putstr_fd.c
		src/string/ft_strcat.c
		src/string/ft_strchr.c
		src/string/ft_strclr.c
		src/string/ft_strcmp.c
		src/string/ft_strcpy.c
		src/string/ft_strdel.c
		src/string/ft_strdup.c
		src/string/ft_strequ.c
		src/string/ft_striter.c
		src/string/ft_striteri.c
		src/string/ft_strjoin.c
		src/string/ft_strlcat.c
		src/string/ft_strlen.c
		src/string/ft_strmap.c
		src/string/ft_strmapi.c
		src/string/ft_strncat.c
		src/string/ft_strncmp.c
		src/string/ft_strncpy.c
		src/string/ft_strnequ.c
		src/string/ft_strnew.c
		src/string/ft_strnstr.c
		src/string/ft_strrchr.c
		src/string/ft_strsplit.c
		src/string/ft_strstr.c
		src/string/ft_strsub.c
		src/string/ft_strtrim.c
		src/string/ft_tolower.c
		src/string/ft_toupper.c

		src/format/ft_itoa.c
		src/format/ft_ultoa.c
		src/format/ft_ftoa.c

		src/list/ft_lstadd.c
		src/list/ft_lstaddend.c
		src/list/ft_lstdel.c
		src/list/ft_lstdelone.c
		src/list/ft_lstiter.c
		src/list/ft_lstmap.c
		src/list/ft_lstnew.c

		src/math/ft_sqrt.c
		src/math/ft_pow.c

		src/ft_swap.c
		src/get_next_line.c
		src/t_buff.c
		src/endian.c

		src/printf/ft_printf.c
		src/printf/handlers.c
		)
