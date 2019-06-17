/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_print_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 22:26:41 by thdelmas          #+#    #+#             */
/*   Updated: 2019/06/17 19:34:21 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	sh_print_env(t_sh *sh, t_cmd *cmd)
{
	char **tmp;

	cmd = (void *)cmd;
	tmp = sh->env;
	if (tmp)
		while (*tmp)
		{
			if (**tmp)
				ft_putendl(*(tmp++));
		}
}
