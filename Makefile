# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nboste <nboste@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/14 20:14:11 by nboste            #+#    #+#              #
#    Updated: 2017/10/22 13:10:47 by nboste           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

FLG = -Wall -Wextra -Werror

SRC = srcs/main.c \
	  srcs/error.c \
	  srcs/drawer.c \
	  srcs/wolf3d.c \
	  srcs/event.c \
	  srcs/sc_intro.c \
	  srcs/sc_basic.c \
	  srcs/player_event.c \
	  srcs/raycasting.c \
	  srcs/color.c \
	  srcs/background.c \
	  srcs/map_reader.c \
	  srcs/texture.c \

OBJ = $(SRC:%.c=%.o)

INC = -I./incs \
	  -I./libft/includes \
	  -I/usr/include \
	  -I ~/Library/Frameworks/SDL2.framework/Headers \

LIB = -L./libft \
	  -F ~/Library/Frameworks/SDL2.framework/Versions/Current \
	  ~/Library/Frameworks/SDL2_image.framework/Versions/Current/SDL2_image \

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLG) $(LIB) $(INC) $(SRC) -lm -lft -framework SDL2 -o $(NAME) -O3

debug:
	make -C libft
	gcc $(FLG) $(LIB) $(INC) $(SRC) -lm -lft -framework SDL2 -o $(NAME) -O3 -g

linux:
	make -C libft
	gcc $(FLG) $(INC) $(SRC) $(LIB) -lm -lft -lSDL2 -o $(NAME) -O3 -flto

linuxd:
	make -C libft
	gcc $(FLG) $(LIB) $(INC) $(SRC) -lm -lft -lSDL2 -o $(NAME) -O3 -g -pg

clean:
	make -C libft clean
	rm -f $(NAME)

fclean: clean
	make -C libft fclean
	rm -rf $(OBJ)

re: clean all
