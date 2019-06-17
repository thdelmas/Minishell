/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:48:58 by thdelmas          #+#    #+#             */
/*   Updated: 2019/06/17 19:45:39 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef sh_H
# define sh_H

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

typedef struct		s_sh
{
	char			*flags;
	char			**prim_env;
	char			**env;
	t_cmd			*cmd_begin;
	t_cmd			*cmd;
}					t_sh;

void				sh_loop(t_sh *sh);
void				sh_prompt();
char				**sh_find_env(char *name, char **env);
void				sh_parse_arg(int ac, char **av, char **env);
void				sh_call_bin(t_sh *sh, t_cmd *cmd);
void				sh_make_arg(t_sh *sh, t_cmd *cmd);
void				sh_cd(t_sh *sh, t_cmd *cmd);
void				sh_echo(t_sh *sh, t_cmd *cmd);
void				sh_print_env(t_sh *sh, t_cmd *cmd);
void				sh_setenv(t_sh *sh, t_cmd *cmd);
void				sh_unsetenv(t_sh *sh, t_cmd *cmd);
void				sh_var_add(char ***tab, char *name, char *value);
void				sh_var_del(char ***tab, char *name);
void				sh_free_tab(char ***tab);
void				sh_free_sh(t_sh **sh);
void				sh_free_cmd(t_cmd **cmd);
char				**sh_split_whitespaces(char *str);
char				**sh_tabdup(char **tab);
char				*sh_tilde_exp(t_sh *sh, char *str);
char				*sh_dollar_exp(t_sh *sh, char *str);
t_sh				*sh_init_sh(char **env);
t_cmd				*sh_init_cmd();

#endif