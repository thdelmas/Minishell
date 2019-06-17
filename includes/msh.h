/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:48:58 by thdelmas          #+#    #+#             */
/*   Updated: 2019/06/03 22:23:05 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct		s_cmd
{
	char			**av;
	int				status;
	struct s_cmd	*next;
}					t_cmd;

typedef struct		s_msh
{
	char			*flags;
	char			**prim_env;
	char			**env;
	t_cmd			*cmd_begin;
	t_cmd			*cmd;
}					t_msh;

void				test_tok(char *line);
void				msh_loop(t_msh *msh);
void				msh_prompt();
char				**msh_find_env(char *name, char **env);
void				msh_parse_arg(int ac, char **av, char **env);
void				msh_call_bin(t_msh *msh, t_cmd *cmd);
void				msh_make_arg(t_msh *msh, t_cmd *cmd);
void				msh_cd(t_msh *msh, t_cmd *cmd);
void				msh_echo(t_msh *msh, t_cmd *cmd);
void				msh_print_env(t_msh *msh, t_cmd *cmd);
void				msh_setenv(t_msh *msh, t_cmd *cmd);
void				msh_unsetenv(t_msh *msh, t_cmd *cmd);
void				msh_var_add(char ***tab, char *name, char *value);
void				msh_var_del(char ***tab, char *name);
void				msh_free_tab(char ***tab);
void				msh_free_msh(t_msh **msh);
void				msh_free_cmd(t_cmd **cmd);
char				**msh_split_whitespaces(char *str);
char				**msh_tabdup(char **tab);
char				*msh_tilde_exp(t_msh *msh, char *str);
char				*msh_dollar_exp(t_msh *msh, char *str);
t_msh				*msh_init_msh(char **env);
t_cmd				*msh_init_cmd();

#endif
