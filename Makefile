# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/08 10:55:19 by mbrunel           #+#    #+#              #
#    Updated: 2020/02/10 10:46:10 by mbrunel          ###   ########.fr        #
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

CC =		gcc
CFLAGS =	-Wall -Wextra -I$(INCS_DIR)

SRCS =		nmlx_init.c\
			nmlx_loop.c\
			nmlx_new_win.c\
			nmlx_put_image_to_window.c\
			nmlx_create_new_img.c\
			nmlx_get_data_address.c\
			nmlx_hook.c\
			exit_no_leaks.c\
			sdl_to_x.c

OBJS =		$(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))

C_RED = \033[31m
C_GREEN = \033[32m
C_CYAN = \033[36m
C_NONE = \033[0m

all : $(NAME)

$(NAME): $(OBJS) $(SDL_DIR) $(DIR_LIB_SDL)
	-@$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIB_FT) $@
	@printf "\n$(C_GREEN)[%s]$(C_NONE)\n" $(LIBFT_NAME)
	-@ar rc $(NAME) $(LIB_SDL) $(OBJS)
	@ranlib $@
	@printf "\n$(C_GREEN)[%s]$(C_NONE)\n" $@

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c $(INCS_DIR)/* Makefile
	@mkdir -p $(OBJS_DIR)/
	-@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\n$(C_GREEN)[%s]$(C_NONE)\n" $@

$(SDL_DIR) :
	@tar -xf $(SDL_TAR)
	@printf "$(C_CYAN)starting SDL set up...]$(C_NONE)\n" $@

$(DIR_LIB_SDL):
	@mkdir $(DIR_LIB_SDL)
	@printf "\n$(C_CYAN)[configuring SDL...]$(C_NONE)\n"
	@cd $(SDL_DIR); ./configure --prefix=`pwd`/lib
	@printf "$(C_CYAN)[compiling SDL...]$(C_NONE)\n"
	-@make -C $(SDL_DIR)
	-@make -C $(SDL_DIR) install >/dev/null
	@printf "\n$(C_GREEN)[SDL2]$(C_NONE)\n"

EXEC = tester
S = main.c
MLX_DIR = $(LIBS_DIR)/mlx
MLX = libmlx.dylib

nmlx: $(NAME)
	$(CC) $(CFLAGS) $(S) $(NAME) `$(SDL_DIR)/sdl2-config --cflags --libs` -o $(EXEC) && ./$(EXEC)

mlx_lib: $(NAME)
	$(MAKE) -C $(MLX_DIR)
	cp $(MLX_DIR)/$(MLX) .
	gcc $(CFLAGS) $(S) $(LIB_FT) $(MLX) -o $(EXEC) && ./$(EXEC)

clean :
	@rm -rf $(OBJS) $(LIBFT_DIR)/*/*.o a.out $(MLX_DIR)/*.o

fclean : clean
	@rm -rf $(NAME) $(LIB_FT) $(LIBFT_DIR)/libc/libc.a $(EXEC) $(MLX)

fullfclean : fclean
	@rm -rf $(SDL_DIR)

re : fclean all

re_full : fclean_resdl all
