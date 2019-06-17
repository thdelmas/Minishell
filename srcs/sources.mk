# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/13 19:40:02 by thdelmas          #+#    #+#              #
#    Updated: 2019/06/17 20:00:11 by thdelmas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### MAIN FILES ###
C_FILES = \
	main.c \
	get_next_line.c \
	sh_var_add.c \
	sh_var_del.c \
	sh_echo.c \
	sh_init_cmd.c \
	sh_make_arg.c \
	sh_loop.c \
	sh_cd.c \
	sh_prompt.c \
	sh_setenv.c \
	sh_split_whitespaces.c \
	sh_tabdup.c \
	sh_unsetenv.c \
	sh_call_bin.c \
	sh_dollar_exp.c \
	sh_tilde_exp.c \
	sh_find_env.c \
	sh_print_env.c \
	sh_init_sh.c \
	sh_free_sh.c \
	sh_free_cmd.c \
	sh_free_tab.c \

C_FILES_command_edition = \

C_FILES_command_line = \

C_FILES_entrypoint = \

C_FILES_signals = \

C_FILES_tokenizer = \

C_FILES_functions = \

C_FILES_env = \

C_FILES_tools = \

# SUPPA concat loop
C_FILES += $(foreach SUB_DIR,$(SUB_DIRS),$(addprefix $(SUB_DIR)/,$(C_FILES_$(SUB_DIR))))
