/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_print_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 22:26:41 by thdelmas          #+#    #+#             */
/*   Updated: 2019/03/10 18:18:34 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void	msh_print_env(t_msh *msh, t_cmd *cmd)
{
	char **tmp;

	cmd = (void *)cmd;
	tmp = msh->env;
	if (tmp)
		while (*tmp)
		{
			if (**tmp)
				ft_putendl(*(tmp++));
		}
}
