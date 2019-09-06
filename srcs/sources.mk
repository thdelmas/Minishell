# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 23:34:28 by thdelmas          #+#    #+#              #
#    Updated: 2019/09/06 23:35:44 by thdelmas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FILES = \
	main.c \
	msh_call_bin.c \
	msh_cd.c \
	msh_dollar_exp.c \
	msh_echo.c \
	msh_find_env.c \
	msh_free_cmd.c \
	msh_free_msh.c \
	msh_free_tab.c \
	msh_init_cmd.c \
	msh_init_msh.c \
	msh_is_builtin.c \
	msh_loop.c \
	msh_make_arg.c \
	msh_print_env.c \
	msh_prompt.c \
	msh_setenv.c \
	msh_split_whitespaces.c \
	msh_tabdup.c \
	msh_tilde_exp.c \
	msh_unsetenv.c \
	msh_var_add.c \
	msh_var_del.c \

C_FILES += $(foreach SUB_DIR,$(SUB_DIRS),$(addprefix $(SUB_DIR)/,$(C_FILES_$(SUB_DIR))))
