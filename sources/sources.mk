# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 23:34:28 by thdelmas          #+#    #+#              #
#    Updated: 2019/10/29 14:11:22 by thdelmas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FILES = \
	main.c \
	sh.c \
	get_next_line.c \
	sh_call_bin.c \
	sh_cd.c \
	sh_dollar_exp.c \
	sh_echo.c \
	sh_find_env.c \
	sh_free_cmd.c \
	sh_free_sh.c \
	sh_free_tab.c \
	sh_init_cmd.c \
	sh_init_sh.c \
	sh_loop.c \
	sh_make_arg.c \
	sh_print_env.c \
	sh_prompt.c \
	sh_export.c \
	sh_split_whitespaces.c \
	sh_tabdup.c \
	sh_tilde_exp.c \
	sh_unset.c \
	sh_var_add.c \
	sh_var_del.c \

C_FILES_env= \
	sh_setenv.c \
	sh_getenv.c \
	sh_unsetenv.c \

C_FILES_line_edition= \
	sh_init_termcaps.c \
	sh_move_cursor.c \

C_FILES_signals= \
	sh_handle_signals.c \
	sh_handle_sigint.c

C_FILES_tools= \
	sh_constructor.c \
	sh_destructor.c \
	sh_init_tty.c \
	sh_exitpoint.c \
	sh_shclr.c \

C_FILES += $(foreach SUB_DIR,$(SUB_DIRS),$(addprefix $(SUB_DIR)/,$(C_FILES_$(SUB_DIR))))
