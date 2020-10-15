# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 01:02:41 by mbrunel           #+#    #+#              #
#    Updated: 2020/10/15 20:24:11 by mbrunel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libnmlx.a

OS := $(shell uname)
ifeq ($(OS), Linux)
SDL2=/usr/include/SDL2
INSTALL_SDL2:=sudo apt install libsdl2-dev
else ifeq ($(OS), Darwin)
SDL2=$(HOME)/.brew/Cellar/sdl2
INSTALL_SDL2:=brew install sdl2
endif

BUILD=.build
D_SRC=src
D_INC=inc

D_OBJ=$(BUILD)/obj
D_DEP=$(BUILD)/dep
D_SUB=
DIRS:=$(D_DEP) $(addprefix $(D_DEP)/, $(D_SUB))\
	$(D_OBJ) $(addprefix $(D_OBJ)/, $(D_SUB))

CC=gcc
CFLAGS=-Wall -Wextra -Ofast -Werror
DFLAGS=-MP -MMD -MF $(D_DEP)/$*.d -MT $@
IFLAGS=-I$(D_INC) `sdl2-config --cflags`
CPPFLAGS=$(CFLAGS) $(IFLAGS) $(DFLAGS)
LDFLAGS= `sdl2-config --libs` $(NAME)

C_RED=\033[31m
C_GREEN=\033[32m
C_CYAN=\033[36m
C_NONE=\033[0m
BUILD_MSG=$(C_GREEN)✔$(C_NONE)
REMOVE_MSG=$(C_RED)𐄂$(C_NONE)

INC=$(D_INC)/minishell.h

SRC=nmlx_destroy_img.c\
	nmlx_destroy_win.c\
	nmlx_do_key_repeat.c\
	nmlx_get_data_address.c\
	nmlx_hook.c\
	nmlx_init.c\
	nmlx_loop.c\
	nmlx_loop_hook.c\
	nmlx_loop_stop.c\
	nmlx_mouse.c\
	nmlx_new_img.c\
	nmlx_new_win.c\
	nmlx_put_image_to_window.c\
	nmlx_quit.c\
	nmlx_sdl_extension_stuff.c\
	nmlx_sdl_to_x.c\
	nmlx_smart_hook.c

OBJ:=$(patsubst %.c, $(D_OBJ)/%.o, $(SRC))
DEP:=$(patsubst %.c, $(D_DEP)/%.d, $(SRC))

all :
	@$(MAKE) -s $(NAME)

$(NAME) : $(SDL2) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@printf "$(BUILD_MSG) %s\n" $@

clean :
	@rm -rf $(BUILD)
	@printf "$(REMOVE_MSG) rm %s\n" $(BUILD)

fclean : clean
	@rm -rf $(NAME) test
	@printf "$(REMOVE_MSG) rm %s\n" $(NAME) test

re : fclean all test

$(SDL2) :
	$(INSTALL_SDL2)

test : all
	$(CC) $(CPPFLAGS) test.c $(LDFLAGS) -o test

$(BUILD) :
	@mkdir -p $@ $(DIRS)
	@printf "$(BUILD_MSG) %s\n" $@

-include $(DEP)

$(D_OBJ)/%.o : $(D_SRC)/%.c  $(GIT) Makefile | $(BUILD)
	@$(CC) $(CPPFLAGS) -c $< -o $@
	@printf "$(BUILD_MSG) %s\n" $<

.PHONY: all clean fclean re test
