# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/08 10:55:19 by mbrunel           #+#    #+#              #
#    Updated: 2020/02/08 11:06:26 by mbrunel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_DIR = libs
INC_DIR = incs
SRC_DIR = srcs
OBJ_DIR = objs

CC =		gcc
CFLAGS =	-Wall -Wextra
OFLAGS =	$(LIB_DIR)/$(LIBFT_DIR)/$(LIBFT) $(LIB_DIR)/libSDL2.so
NAME =		exec

SRCS =		main.c

OBJS =		$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

LIBFT_DIR = libft
LIBFT = libft.a

$(NAME):	$(OBJS)
			$(MAKE) -C $(LIB_DIR)/$(LIBFT_DIR)
			$(CC) $(OFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INC_DIR)/* Makefile
			mkdir -p $(OBJ_DIR)/
			$(CC) $(CFLAGS) -c $< -o $@


all :	${NAME}

clean :
			rm -rf $(OBJS) $(LIB_DIR)/$(LIBFT_DIR)/*/*.o

fclean : clean
			rm -rf $(NAME) $(LIB_DIR)/$(LIBFT_DIR)/$(LIBFT) $(LIB_DIR)/$(LIBFT_DIR)/libc/libc.a

re :	fclean all
