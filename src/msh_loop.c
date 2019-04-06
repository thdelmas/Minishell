/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 22:30:46 by thdelmas          #+#    #+#             */
/*   Updated: 2019/03/11 14:46:03 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void	(*msh_is_builtin(t_cmd *cmd))(t_msh *, t_cmd *)
{
	if (!ft_strcmp((cmd->av)[0], "cd"))
		return (&msh_cd);
	else if (!ft_strcmp((cmd->av)[0], "env"))
		return (&msh_print_env);
	else if (!ft_strcmp((cmd->av)[0], "echo"))
		return (&msh_echo);
	else if (!ft_strcmp((cmd->av)[0], "setenv"))
		return (&msh_setenv);
	else if (!ft_strcmp((cmd->av)[0], "unsetenv"))
		return (&msh_unsetenv);
	return (NULL);
}

void	msh_loop(t_msh *msh)
{
	void	(*f)(t_msh *msh, t_cmd *);
	t_cmd	*tmp;
	t_cmd	*cmd;

	while ((cmd = msh_init_cmd(msh)))
	{
		if (msh->cmd_begin)
			tmp->next = cmd;
		else
			msh->cmd_begin = cmd;
		tmp = cmd;
		msh_make_arg(msh, cmd);
		if (*(cmd->av) && (ft_strcmp(cmd->av[0], "exit"))
				&& (f = msh_is_builtin(cmd)))
			f(msh, cmd);
		else if (*(cmd->av) && (ft_strcmp(cmd->av[0], "exit")))
			msh_call_bin(msh, cmd);
		else
			break ;
	}
}
