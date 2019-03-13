# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lomeress <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/05 15:34:26 by lomeress          #+#    #+#              #
#    Updated: 2019/03/13 12:05:33 by lomeress         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: make all clean fclean re

NAME = scop
CC = gcc

SRC_PATH = ./src/
OBJ_PATH = ./obj/
LIB_PATH = ./lib/
INC_PATH = ./include/ $(LIB_PATH)libft/include/ $(LIB_PATH)glfw/include/

GCC_FLGS = -Werror -Wextra -Wall
GCC_LIBS = -g -lglfw3 -framework AppKit -framework OpenGL -framework IOKit -framework CoreVideo

SRC_NAME = main.c shader.c matrice.c matrice2.c event.c parsing.c parsing2.c texture.c
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft glfw/src

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L$(LIB_PATH),$(LIB_NAME))

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIB_PATH)libft -j
		$(CC) $(GCC_FLGS) $(LIB) -lft $(INC) $(OBJ) $(GCC_LIBS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		mkdir -p $(OBJ_PATH)
		$(CC) $(GCC_FLGS) $(INC) -o $@ -c $<

clean:
		rm -fv $(OBJ)
		rm -rf $(OBJ_PATH)

fclean: clean
		make -C $(LIB_PATH)libft fclean
		rm -fv $(NAME)

re: fclean all
