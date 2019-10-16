# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 23:34:28 by thdelmas          #+#    #+#              #
#    Updated: 2019/10/16 16:13:16 by thdelmas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FILES = \
	main.c \

C_FILES_line_edition= \
	sh_init_termcaps.c \
	sh_move_cursor.c \

C_FILES_signals= \
	sh_handle_signals.c \
	sh_handle_sigint.c

C_FILES_tools= \
	sh_read_tty.c \
	sh_exitpoint.c \

C_FILES += $(foreach SUB_DIR,$(SUB_DIRS),$(addprefix $(SUB_DIR)/,$(C_FILES_$(SUB_DIR))))
