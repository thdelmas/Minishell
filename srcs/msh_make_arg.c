/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_make_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 23:13:33 by thdelmas          #+#    #+#             */
/*   Updated: 2019/03/10 23:38:29 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void	msh_make_arg(t_msh *msh, t_cmd *cmd)
{
	int i;

	i = 0;
	if (!cmd || !cmd->av || !*(cmd->av))
		return ;
	while (cmd->av[i])
	{
		if (ft_strchr((cmd->av)[i], '$'))
			(cmd->av)[i] = msh_dollar_exp(msh, (cmd->av)[i]);
		if (ft_strchr((cmd->av)[i], '~'))
			(cmd->av)[i] = msh_tilde_exp(msh, (cmd->av)[i]);
		++i;
	}
}
