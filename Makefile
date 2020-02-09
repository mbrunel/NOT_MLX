# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/08 10:55:19 by mbrunel           #+#    #+#              #
#    Updated: 2020/02/09 06:43:19 by mbrunel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = not_mlx.a
LIBFT_NAME = libft.a
SDL_TAR = SDL2-2.0.10.tar.gz

LIBS_DIR = libs
INCS_DIR = incs
SRCS_DIR = srcs
OBJS_DIR = objs
LIBFT_DIR = $(LIBS_DIR)/libft
SDL_DIR = SDL2-2.0.10
INC_SDL = $(SDL_DIR)/include
DIR_LIB_SDL = $(SDL_DIR)/lib

LIB_FT = $(LIBFT_DIR)/$(LIBFT_NAME)
LIB_SDL = $(DIR_LIB_SDL)/lib/libSDL2.so

CC =		gcc
CFLAGS =	-Wall -Wextra -I$(INCS_DIR)

SRCS = hop.c\
		open_tmp.c

OBJS =		$(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))

C_RED = \033[31m
C_GREEN = \033[32m
C_CYAN = \033[36m
C_NONE = \033[0m

all : $(NAME)

$(NAME):	$(OBJS) $(SDL_DIR) $(DIR_LIB_SDL)
			$(MAKE) -C $(LIBFT_DIR)
			cp $(LIB_FT) $@
			ar rc $(NAME) $(LIB_FT) $(LIB_SDL) $(OBJS)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c $(INCS_DIR)/* Makefile
			mkdir -p $(OBJS_DIR)/
			$(CC) $(CFLAGS) -c $< -o $@

$(SDL_DIR) :
			tar -xf $(SDL_TAR)
			@printf "RTv1:  %-25s$(C_CYAN)[extracted]$(C_NONE)\n" $@

$(DIR_LIB_SDL):
	mkdir $(DIR_LIB_SDL)
	@printf "\n$(C_CYAN)[configuring SDL]$(C_NONE)\n"
	cd $(SDL_DIR); ./configure --prefix=`pwd`/lib
	@printf "$(C_CYAN)[compiling SDL]$(C_NONE)\n"
	make -C $(SDL_DIR)
	make -C $(SDL_DIR) install >/dev/null

comp: all
		$(CC) $(CFLAGS) main.c $(NAME) && ./a.out

clean :
			rm -rf $(OBJS) $(LIBFT_DIR)/*/*.o a.out

fclean : clean
			rm -rf $(NAME) $(LIB_FT) $(LIBFT_DIR)/libc/libc.a

fclean_resdl : fclean
			rm -rf $(SDL_DIR)

re : fclean all

re_full : fclean_resdl all