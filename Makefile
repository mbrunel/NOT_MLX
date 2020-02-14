# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/08 10:55:19 by mbrunel           #+#    #+#              #
#    Updated: 2020/02/14 02:03:27 by mbrunel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libnmlx.a

LIBS_DIR = libs
INCS_DIR = incs
SRCS_DIR = srcs
OBJS_DIR = objs

SDL_TAR = $(LIBS_DIR)/SDL2-2.0.10.tar.gz
SDL_UNTAR = SDL2-2.0.10
SDL_DIR = $(LIBS_DIR)/$(SDL_UNTAR)
INC_SDL = $(SDL_DIR)/include
DIR_LIB_SDL = $(SDL_DIR)/lib

SDL_IMG_TAR = $(LIBS_DIR)/SDL2_image-2.0.5.tar.gz
SDL_IMG_UNTAR = SDL2_image-2.0.5
SDL_IMG_DIR = $(LIBS_DIR)/$(SDL_IMG_UNTAR)
INC_SDL_IMG = $(SDL_IMG_DIR)/include
DIR_LIB_SDL_IMG = $(SDL_IMG_DIR)/lib

CC =		gcc
CFLAGS =	-Wall -Wextra -I$(INCS_DIR)
LINKER_FLAGS =	`$(SDL_DIR)/sdl2-config --libs`

SRCS =		nmlx_init.c\
			nmlx_loop.c\
			nmlx_new_win.c\
			nmlx_put_image_to_window.c\
			nmlx_new_img.c\
			nmlx_get_data_address.c\
			nmlx_hook.c\
			nmlx_quit.c\
			nmlx_sdl_to_x.c\
			nmlx_destroy_img.c\
			nmlx_destroy_win.c\
			nmlx_mouse.c\
			nmlx_loop_hook.c\
			nmlx_smart_hook.c\
			nmlx_do_key_repeat.c\
			nmlx_loop_stop.c\
			nmlx_sdl_extension_stuff.c

OBJS =		$(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))

C_RED = \033[31m
C_GREEN = \033[32m
C_CYAN = \033[36m
C_NONE = \033[0m

all : $(NAME)

$(NAME): $(OBJS) $(SDL_DIR) $(DIR_LIB_SDL) #$(SDL_IMG_DIR) $(DIR_LIB_SDL_IMG)
	-@ar rc $(NAME) $(LIB_SDL) $(LIB_SDL_IMG) $(OBJS)
	@ranlib $@
	@printf "\n$(C_GREEN)[%s]$(C_NONE)\n" $@

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c $(INCS_DIR)/* Makefile
	@mkdir -p $(OBJS_DIR)/
	-@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\n$(C_GREEN)[%s]$(C_NONE)\n" $@

$(SDL_DIR) :
	@tar -xf $(SDL_TAR)
	mv $(SDL_UNTAR) $(SDL_DIR)
	@printf "$(C_CYAN)starting SDL set up...]$(C_NONE)\n" $@

$(DIR_LIB_SDL):
	@mkdir $(DIR_LIB_SDL)
	@printf "\n$(C_CYAN)[configuring SDL...]$(C_NONE)\n"
	@cd $(SDL_DIR); ./configure --prefix=`pwd`/lib
	@printf "$(C_CYAN)[compiling SDL...]$(C_NONE)\n"
	-@make -C $(SDL_DIR)
	-@make -C $(SDL_DIR) install >/dev/null
	@printf "\n$(C_GREEN)[SDL2]$(C_NONE)\n"

# $(SDL_IMG_DIR) :
# 	@tar -xf $(SDL_IMG_TAR)
# 	mv $(SDL_IMG_UNTAR) $(SDL_IMG_DIR)
# 	@printf "$(C_CYAN)starting SDL_IMG set up...]$(C_NONE)\n" $@

# $(DIR_LIB_SDL_IMG):
# 	@mkdir $(DIR_LIB_SDL_IMG)
# 	@printf "\n$(C_CYAN)[configuring SDL_IMG...]$(C_NONE)\n"
# 	@cd $(SDL_IMG_DIR); ./configure --prefix=`pwd`/lib
# 	@printf "$(C_CYAN)[compiling SDL_IMG...]$(C_NONE)\n"
# 	-@make -C $(SDL_IMG_DIR)
# 	-@make -C $(SDL_IMG_DIR) install >/dev/null
# 	@printf "\n$(C_GREEN)[SDL2_IMG]$(C_NONE)\n"

EXEC = tester
S = test_srcs/main.c

test: $(NAME)
	$(CC) $(CFLAGS) $(S) $(NAME) $(LINKER_FLAGS) -o $(EXEC) && ./$(EXEC)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME) $(EXEC) $(MLX)

fullfclean : fclean
	@rm -rf $(SDL_DIR) $(SDL_IMG_DIR)

re : fclean all

re_full : fclean_resdl all
