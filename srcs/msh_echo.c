/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:33:03 by thdelmas          #+#    #+#             */
/*   Updated: 2019/03/10 18:17:08 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void	msh_echo(t_msh *msh, t_cmd *cmd)
{
	int i;
	int opt;

	msh = (void *)msh;
	opt = 0;
	if (cmd->av && cmd->av[1])
		opt = !(ft_strcmp("-n", (cmd->av)[1]));
	i = (opt) ? 2 : 1;
	while ((cmd->av)[i])
	{
		if (i > 1 + opt)
			ft_putchar(' ');
		ft_putstr((cmd->av)[i++]);
	}
	if (!opt)
		ft_putchar('\n');
}
