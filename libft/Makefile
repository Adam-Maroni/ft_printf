NAME = libft.a
CC = clang
FLAGS = -Wall -Werror -Wextra
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_issign.c ft_isspace.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_uitoa.c ft_putstr_ret.c ft_putchar_ret.c
OBJ = $(SRC:.c=.o)
SRC_BONUS = ft_lstadd_back.c  ft_lstclear.c  ft_lstiter.c ft_lstmap.c ft_lstsize.c ft_lstadd_front.c ft_lstdelone.c ft_lstlast.c ft_lstnew.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

%.o: %.c
		$(CC) $? -c $(FLAGS) -o $@

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)	

all: $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)	

re: fclean all

bonus:
	$(CC) -c $(FLAGS) $(SRC_BONUS)
	ar rc $(NAME) $(OBJ_BONUS)
	ranlib $(NAME)

so:
	$(CC) -c -fPIC $(FLAGS) $(SRC) $(SRC_BONUS)
	clang -shared -o libft.so $(OBJ) $(OBJ_BONUS)
