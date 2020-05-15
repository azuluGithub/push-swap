NAME = libft.a

SRC = ft_atoi.c \
		ft_bzero.c \
		ft_isdigit.c \
		ft_memset.c \
		ft_memalloc.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putchar_fd.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_strcpy.c \
		ft_strcmp.c \
		ft_strcat.c \
		ft_strdel.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strnew.c \
		ft_strsplit.c \
		ft_strsub.c \
		ft_putstr.c \
		get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all