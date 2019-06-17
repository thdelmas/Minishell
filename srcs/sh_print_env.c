/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_print_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 22:26:41 by thdelmas          #+#    #+#             */
/*   Updated: 2019/06/17 20:33:43 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		sh_print_env(int ac, char **av, char **ev)
{
	char **tmp;

	tmp = ev;
	if (tmp)
		while (*tmp)
		{
			if (**tmp)
				ft_putendl(*(tmp++));
		}
	return (0);
}
