/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:33:03 by thdelmas          #+#    #+#             */
/*   Updated: 2019/06/17 20:27:21 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		sh_echo(int ac, char **av, char **ev)
{
	int i;
	int opt;

	opt = 0;
	if (av && av[1])
		opt = !(ft_strcmp("-n", av[1]));
	i = (opt) ? 2 : 1;
	while (av[i])
	{
		if (i > 1 + opt)
			ft_putchar(' ');
		ft_putstr(av[i++]);
	}
	if (!opt)
		ft_putchar('\n');
	return (0);
}
