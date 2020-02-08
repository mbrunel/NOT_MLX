OTHER_DIR =	others_fcts
FT_FPRINTF_DIR = ft_fprintf
LIBC_DIR = libc

CC =		gcc
CFLAGS =	-Wall -Wextra -I./$(OTHER_DIR)
NAME =		libft.a

SRC = 		$(addprefix $(OTHER_DIR)/, get_next_line.c)
OBJ =		$(SRC:%.c=%.o)

$(NAME):	${OBJ}
			$(MAKE) -C $(LIBC_DIR)
			$(MAKE) -C $(FT_FPRINTF_DIR)
			cp $(LIBC_DIR)/libc.a $@
			ar rc $@ $< $(FT_FPRINTF_DIR)/*.o
			ranlib $@

all:		${NAME}

clean:
			rm -f ${OBJ} $(FT_FPRINTF_DIR)/*.o $(LIBC_DIR)/*.o

fclean:		clean
			rm -f ${NAME} $(LIBC_DIR)/libc.a

re:			fclean all

.PHONY:		all clean fclean re

