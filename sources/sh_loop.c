/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 22:30:46 by thdelmas          #+#    #+#             */
/*   Updated: 2019/09/10 12:51:29 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osh.h"

void	(*sh_is_builtin(t_cmd *cmd))(t_osh *, t_cmd *)
{
	if (!ft_strcmp((cmd->av)[0], "cd"))
		return (&sh_cd);
	else if (!ft_strcmp((cmd->av)[0], "env"))
		return (&sh_print_env);
	else if (!ft_strcmp((cmd->av)[0], "echo"))
		return (&sh_echo);
	else if (!ft_strcmp((cmd->av)[0], "setenv"))
		return (&sh_setenv);
	else if (!ft_strcmp((cmd->av)[0], "unsetenv"))
		return (&sh_unsetenv);
	return (NULL);
}

void	sh_loop(t_osh *sh)
{
	void	(*f)(t_osh *sh, t_cmd *);
	t_cmd	*tmp;
	t_cmd	*cmd;

	while ((cmd = sh_init_cmd(sh)))
	{
		if (sh->cmd_begin)
			tmp->next = cmd;
		else
			sh->cmd_begin = cmd;
		tmp = cmd;
		sh_make_arg(sh, cmd);
		if (*(cmd->av) && (ft_strcmp(cmd->av[0], "exit"))
				&& (f = sh_is_builtin(cmd)))
			f(sh, cmd);
		else if (*(cmd->av) && (ft_strcmp(cmd->av[0], "exit")))
			sh_call_bin(sh, cmd);
		else
			break ;
	}
}
