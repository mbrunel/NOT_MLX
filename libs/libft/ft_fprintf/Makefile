CC =		gcc

CFLAGS =	-Wall -Wextra

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

OBJ =	$(patsubst %.c, %.o, $(SRC))

LIBFT_DIR = ../libft

LIBFT = libft.a

%.o : %.c
	-@$(CC) $(CFLAGS) -c $< -o $@

all:		$(OBJ)

clean:
			rm -f ${OBJ} $(LIBFT_DIR)/*.o

fclean:		clean
			rm -f ${NAME} $(LIBFT_DIR)/$(LIBFT)

re:			fclean all

comp:		re
			${CC} ${CFLAGS} main.c ${NAME}
			make clean

.PHONY:		all clean fclean re

