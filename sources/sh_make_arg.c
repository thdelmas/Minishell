/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_make_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 23:13:33 by thdelmas          #+#    #+#             */
/*   Updated: 2019/09/10 13:55:21 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osh.h"

void	sh_make_arg(t_osh *sh, t_cmd *cmd)
{
	int i;

	i = 0;
	if (!cmd || !cmd->av || !*(cmd->av))
		return ;
	while (cmd->av[i])
	{
		if (ft_strchr((cmd->av)[i], '$'))
			(cmd->av)[i] = sh_dollar_exp(sh, (cmd->av)[i]);
		if (ft_strchr((cmd->av)[i], '~'))
			(cmd->av)[i] = sh_tilde_exp(sh, (cmd->av)[i]);
		++i;
	}
}
