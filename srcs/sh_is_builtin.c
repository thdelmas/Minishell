/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_is_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:12:33 by thdelmas          #+#    #+#             */
/*   Updated: 2019/06/17 19:32:47 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	(*sh_is_builtin(t_cmd *cmd))(t_sh *, t_cmd *)
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
