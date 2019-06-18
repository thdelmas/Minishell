# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 19:41:15 by thdelmas          #+#    #+#              #
#    Updated: 2019/06/18 17:32:07 by thdelmas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := msh
PROJECT := MINISHELL
RM = /bin/rm

### Directories ###
SRC_DIR := ./srcs
INC_DIR := ./includes
OBJ_DIR := ./.obj

### SUB FILES ###
SUB_DIRS := \

### INCLUDE SRC MAKEFILE ###
include $(SRC_DIR)/sources.mk

### INCLUDE INC MAKEFILE ###
include $(INC_DIR)/includes.mk


### ALL SUB DIRS ###
SRC_SUB_DIRS = $(addprefix $(SRC_DIR)/,$(SUB_DIRS))
OBJ_SUB_DIRS = $(addprefix $(OBJ_DIR)/,$(SUB_DIRS))
INC_SUB_DIRS = $(addprefix $(INC_DIR)/,$(SUB_DIRS))


### MAIN AND SUB FILES ###
O_FILES = $(C_FILES:.c=.o)


### Full Paths ###
SRC = $(addprefix $(SRC_DIR)/,$(C_FILES))
OBJ = $(addprefix $(OBJ_DIR)/,$(O_FILES))
INC = $(addprefix $(INC_DIR)/,$(H_FILES))


### Lib ###
LIB_FT_DIR = ./libft
LIB_FT = $(addprefix $(LIB_FT_DIR)/,libft.a)
LIB_FT_INC_DIR = ./libft/includes
LIB_FT_LNK = -L ./libft -lft

LIB_SHBUILTINS_DIR = ./libshbuiltins
LIB_SHBUILTINS = $(addprefix $(LIB_SHBUILTINS_DIR)/,libshbuiltins.a)
LIB_SHBUILTINS_INC_DIR = $(LIB_SHBUILTINS_DIR)/includes
LIB_SH_BUILTINS_LNK = -L $(LIB_SHBUILTINS_DIR) -lshbuiltins

###  CC && FLAGS ###
CC = clang
CFLAGS = \
		 $(addprefix -I ,$(INC_DIR) $(INC_SUB_DIRS) $(LIB_FT_INC_DIR) $(LIB_SHBUILTINS_INC_DIR)) \
		  #-Wall -Werror -Wextra

LFLAGS = -ltermcap \
		 -lncurses \
		 $(LIB_FT_LNK) $(LIB_FT) \
		 $(LIB_SHBUILTINS_LNK) $(LIB_SHBUILTINS)


.PHONY: all clean fclean re

all: hey_msg $(LIB_FT) $(LIB_SHBUILTINS) $(NAME) bye_msg

### Lib compil ###
$(LIB_FT): lib_msg
	@make -C $(LIB_FT_DIR)

$(LIB_SHBUILTINS): lib_msg
	@make -C $(LIB_SHBUILTINS_DIR)

### Mkdir obj ###
.ONESHELL:
$(OBJ_DIR): mkdir_msg
	mkdir -p $(OBJ_DIR) $(OBJ_SUB_DIRS)

### Compilation ###
.ONESHELL:
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC) Makefile | compil_msg
	@printf "$(BBLUE)$(@F): $(CLEAR)"
	@$(CC) $(LFlAGS) $(CFLAGS) -o $@ -c $<
	@printf "$(BBLUE)Done !$(CLEAR)\n"

### Link ###
.ONESHELL:
$(NAME): $(OBJ_DIR) $(OBJ) | link_msg
	$(CC) $(OBJ) $(LFLAGS) -o $(NAME)

### Clean ###
.ONESHELL:
clean: clean_msg
	$(RM) -rf $(OBJ_DIR)
	@make -C $(LIB_FT_DIR) clean
	@make -C $(LIB_SHBUILTINS_DIR) clean

.ONESHELL:
fclean: clean fclean_msg
	$(RM) -rf $(NAME)
	@make -C $(LIB_FT_DIR) fclean
	@make -C $(LIB_SHBUILTINS_DIR) fclean

re: fclean all

### INCLUDE TOOLS MAKEFILE ###
include ./tools.mk
