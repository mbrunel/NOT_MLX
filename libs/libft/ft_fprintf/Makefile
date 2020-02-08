CC =		gcc

CFLAGS =	-Wall -Wextra -I./libftprintf.h -I../libft/libft.h

NAME =		ft_printf.a

SRC =	fprintf.c \
		matrix.c \
		flags.c \
		numconvs.c \
		strconvs.c \
		affs.c \
		flags2.c \
		affs_utils.c \
		hexconvs.c \
		convs_utils.c \
		matrix.c \
		printf_utils.c \

OBJ =		${SRC:%.c=%.o}

LIBFT_DIR = ../libft

LIBFT = libft.a

$(NAME):	${OBJ}

all:		${NAME}

clean:
			rm -f ${OBJ} $(LIBFT_DIR)/*.o

fclean:		clean
			rm -f ${NAME} $(LIBFT_DIR)/$(LIBFT)

re:			fclean all

comp:		re
			${CC} ${CFLAGS} main.c ${NAME}
			make clean

.PHONY:		all clean fclean re

