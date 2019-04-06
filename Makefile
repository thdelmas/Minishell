# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/24 15:33:18 by thdelmas          #+#    #+#              #
#    Updated: 2019/03/11 14:50:19 by thdelmas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Werror -Wall -Wextra 

FT	= ./libft
FT_LIB = $(addprefix $(FT)/,libft.a)
FT_INC = -I ./libft
FT_LNK = -L ./libft -l ft

SRC_DIR = ./src
INC_DIR = ./includes
OBJ_DIR = ./obj

C_FILES =	main.c \
			msh_loop.c \
			msh_cd.c \
			msh_echo.c \
			msh_find_env.c \
			msh_call_bin.c \
			msh_setenv.c \
			msh_unsetenv.c \
			msh_print_env.c \
			msh_free_tab.c \
			msh_tilde_exp.c \
			msh_dollar_exp.c \
			msh_tabdup.c \
			msh_var_add.c \
			msh_var_del.c \
			msh_free_msh.c \
			msh_free_cmd.c \
			msh_init_cmd.c \
			msh_init_msh.c \
			msh_make_arg.c \
			msh_prompt.c \
			msh_split_whitespaces.c
O_FILES = 	$(C_FILES:%.c=%.o)
H_FILES =	msh.h \

SRC = $(addprefix $(SRC_DIR)/,$(C_FILES))
OBJ = $(addprefix $(OBJ_DIR)/,$(O_FILES))
INC = $(addprefix $(INC_DIR)/,$(H_FILES))

all: obj $(FT_LIB) $(NAME)

$(NAME): $(OBJ) $(INC_DIR)/msh.h
	$(CC) $(CFLAGS) $(OBJ) $(FT_LNK) -o $(NAME)

obj:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(FT_INC) -I $(INC_DIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all

.PHONY: all, clean, fclean, re
