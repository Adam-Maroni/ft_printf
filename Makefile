CC = clang
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRC_ALL = $(SRC_LIBFT) $(SRC_UTILS) $(SRC_FTPRINTF)

#LIBFT
#........................................................................................................................................................................................................
SRC_LIBFT = ./libft/ft_atoi.c ./libft/ft_bzero.c ./libft/ft_calloc.c ./libft/ft_isalnum.c ./libft/ft_isalpha.c ./libft/ft_isascii.c ./libft/ft_isdigit.c ./libft/ft_isprint.c ./libft/ft_issign.c ./libft/ft_isspace.c ./libft/ft_itoa.c ./libft/ft_lstadd_back.c ./libft/ft_lstadd_front.c ./libft/ft_lstclear.c ./libft/ft_lstdelone.c ./libft/ft_lstiter.c ./libft/ft_lstlast.c ./libft/ft_lstmap.c ./libft/ft_lstnew.c ./libft/ft_lstsize.c ./libft/ft_memccpy.c ./libft/ft_memchr.c ./libft/ft_memcmp.c ./libft/ft_memcpy.c ./libft/ft_memmove.c ./libft/ft_memset.c ./libft/ft_putchar.c ./libft/ft_putchar_fd.c ./libft/ft_putendl_fd.c ./libft/ft_putnbr_fd.c ./libft/ft_putstr.c ./libft/ft_putstr_fd.c ./libft/ft_split.c ./libft/ft_strchr.c ./libft/ft_strdup.c ./libft/ft_strjoin.c ./libft/ft_strlcat.c ./libft/ft_strlcpy.c ./libft/ft_strlen.c ./libft/ft_strmapi.c ./libft/ft_strncmp.c ./libft/ft_strnstr.c ./libft/ft_strrchr.c ./libft/ft_strtrim.c ./libft/ft_substr.c ./libft/ft_tolower.c ./libft/ft_toupper.c ./libft/ft_uitoa.c ./libft/ft_putstr_ret.c
OBJ_LIBFT = ./libft/ft_atoi.o ./libft/ft_bzero.o ./libft/ft_calloc.o ./libft/ft_isalnum.o ./libft/ft_isalpha.o ./libft/ft_isascii.o ./libft/ft_isdigit.o ./libft/ft_isprint.o ./libft/ft_issign.o ./libft/ft_isspace.o ./libft/ft_itoa.o ./libft/ft_lstadd_back.o ./libft/ft_lstadd_front.o ./libft/ft_lstclear.o ./libft/ft_lstdelone.o ./libft/ft_lstiter.o ./libft/ft_lstlast.o ./libft/ft_lstmap.o ./libft/ft_lstnew.o ./libft/ft_lstsize.o ./libft/ft_memccpy.o ./libft/ft_memchr.o ./libft/ft_memcmp.o ./libft/ft_memcpy.o ./libft/ft_memmove.o ./libft/ft_memset.o ./libft/ft_putchar.o ./libft/ft_putchar_fd.o ./libft/ft_putendl_fd.o ./libft/ft_putnbr_fd.o ./libft/ft_putstr.o ./libft/ft_putstr_fd.o ./libft/ft_split.o ./libft/ft_strchr.o ./libft/ft_strdup.o ./libft/ft_strjoin.o ./libft/ft_strlcat.o ./libft/ft_strlcpy.o ./libft/ft_strlen.o ./libft/ft_strmapi.o ./libft/ft_strncmp.o ./libft/ft_strnstr.o ./libft/ft_strrchr.o ./libft/ft_strtrim.o ./libft/ft_substr.o ./libft/ft_tolower.o ./libft/ft_toupper.o ./libft/ft_uitoa.o ./libft/ft_putstr_ret.o
LIBFT_FOLDER=./libft
libft_rule:$(OBJ_LIBFT)
#	cd $(LIBFT_FOLDER) && make re
clean_libft:
	rm -rf $(LIBFT_FOLDER)/*.o
#........................................................................................................................................................................................................



#UTILS
#........................................................................................................................................................................................................
SRC_UTILS =  utils/handle_c.c utils/handle_convertor.c utils/handle_d.c utils/handle_hexa_conversions.c utils/handle_p.c utils/handle_percent.c utils/handle_s.c utils/handle_u.c utils/precise_int.c utils/zero_pad_int.c utils/is_convertor.c utils/handle_width.c utils/handle_precision.c utils/handle_digit.c
OBJ_UTILS = utils/handle_c.o utils/handle_convertor.o utils/handle_d.o utils/handle_hexa_conversions.o utils/handle_p.o utils/handle_percent.o utils/handle_s.o utils/handle_u.o utils/precise_int.o utils/zero_pad_int.o utils/is_convertor.o utils/handle_width.o utils/handle_precision.o utils/handle_digit.o
utils: $(OBJ_UTILS)
clean_utils:
	rm -rf ./utils/*.o
#........................................................................................................................................................................................................

#FTPRINTF
#........................................................................................................................................................................................................
SRC_FTPRINTF = ft_printf.c
OBJ_FTPRINTF = ft_printf.o
ftprintf: $(OBJ_FTPRINTF)
clean_ftprintf:
	rm -rf ./*.o
#........................................................................................................................................................................................................

%.o:%.c
	$(CC) $(FLAGS) -c $^ -o $@ -I ./libft/libft.a

$(NAME):libft_rule utils ftprintf
	ar rc $(NAME) $(OBJ_UTILS) $(OBJ_FTPRINTF) $(OBJ_LIBFT)
	ranlib $(NAME)

all: $(NAME)

clean: clean_libft clean_utils clean_ftprintf

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_FOLDER)/libft.a

re: fclean all



#DEBUG AND TEST
#........................................................................................................................................................................................................
test:
	$(CC) -fsanitize=address -g3 $(SRC_ALL) main.c
	./a.out | cat -e

debug:
	$(CC) -g $(SRC_ALL) main.c

lldb: debug
	lldb ./a.out

gdb: debug
	gdb ./a.out
#........................................................................................................................................................................................................
