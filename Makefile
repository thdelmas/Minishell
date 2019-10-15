# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/05 17:18:13 by thdelmas          #+#    #+#              #
#    Updated: 2019/10/15 15:52:39 by thdelmas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell
PROJECT := MINISHELL
AUTHORS := Thdelmas

RM = /bin/rm

### Directories ###
SRC_DIR := ./srcs
INC_DIR := ./includes
OBJ_DIR := ./.obj

### SUB FILES ###
SUB_DIRS := \
	Signals \
	Tools \

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
FT = ft
FT_DIR = ./lib$(FT)
FT_INC_DIR = $(FT_DIR)/includes
FT_LNK = -L$(FT_DIR) -l$(FT)

###  CC && FLAGS ###
CC = clang
DEBUG_FLAGS = -g3
CFLAGS = \
		 $(addprefix -I ,$(INC_DIR) $(INC_SUB_DIRS) $(FT_INC_DIR)) \
		 $(DEBUG_FLAGS) \
		 -Weverything

LFLAGS = -ltermcap \
		 -lncurses \
		 $(FT_LNK) \



.PHONY: all clean fclean re

all: $(FT) $(NAME) bye_msg

### Lib compil ###
$(FT): | lib_msg
	@make -C $(FT_DIR)

$(SHUTIL): $(FT) | lib_msg
	@make -C $(SHUTIL_DIR)

### Mkdir obj ###
$(OBJ_DIR): | mkdir_msg
	@mkdir -p $(OBJ_DIR) $(OBJ_SUB_DIRS)

### Compilation ###
.ONESHELL:
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC) Makefile | compil_msg
	$(CC) $(CFLAGS) -o $@ -c $<

### Link ###
$(NAME): $(OBJ_DIR) $(OBJ) $(INC) Makefile $(FT_DIR)/libft.a | link_msg
	$(CC) $(OBJ) $(LFLAGS) -o $(NAME)

### Clean ###
$(FT)_clean: | lib_msg
	@make -C $(FT_DIR) clean

clean: $(FT)_clean $(SHUTIL)_clean | clean_msg
	$(RM) -rf $(OBJ_DIR)

$(FT)_fclean: | lib_msg
	@make -C $(FT_DIR) fclean

fclean: $(FT)_fclean | fclean_msg
	$(RM) -rf $(OBJ_DIR)
	$(RM) -rf $(NAME).dSYM
	$(RM) -rf $(NAME)

re: fclean all

### INCLUDE TOOLS MAKEFILE ###
include ./tools.mk
