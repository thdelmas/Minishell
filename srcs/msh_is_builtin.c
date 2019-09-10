/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_is_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:12:33 by thdelmas          #+#    #+#             */
/*   Updated: 2019/09/10 12:29:02 by thdelmas         ###   ########.fr       */
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
