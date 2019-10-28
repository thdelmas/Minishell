/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:48:58 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/28 21:33:48 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSH_H
# define OSH_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/syslimits.h>
# include "libft.h"
# include "sh_types.h"

void				sh_loop(t_osh *sh);
void				sh_prompt();
char				**sh_find_env(char *name, char **env);
void				sh_parse_arg(int ac, char **av, char **env);
void				sh_call_bin(t_osh *sh, t_cmd *cmd);
void				sh_make_arg(t_osh *sh, t_cmd *cmd);
void				sh_cd(t_osh *sh, t_cmd *cmd);
void				sh_echo(t_osh *sh, t_cmd *cmd);
void				sh_print_env(t_osh *sh, t_cmd *cmd);
void				sh_setenv(t_osh *sh, t_cmd *cmd);
void				sh_unsetenv(t_osh *sh, t_cmd *cmd);
void				sh_var_add(char ***tab, char *name, char *value);
void				sh_var_del(char ***tab, char *name);
void				sh_free_tab(char ***tab);
void				sh_free_sh(t_osh **sh);
void				sh_free_cmd(t_cmd **cmd);
char				**sh_split_whitespaces(char *str);
char				**sh_tabdup(char **tab);
char				*sh_tilde_exp(t_osh *sh, char *str);
char				*sh_dollar_exp(t_osh *sh, char *str);
t_osh				*sh_init_osh(char **env);
t_cmd				*sh_init_cmd();

#endif
