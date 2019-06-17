/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:58:56 by thdelmas          #+#    #+#             */
/*   Updated: 2019/06/17 20:31:11 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	sh_check_var(char *str)
{
	str--;
	while (*(++str))
		if (!(ft_isalnum(*(str)) || *str == '_'))
			return (0);
	return (1);
}

int		sh_setenv(int ac, char **av, char **ev)
{
	char	*str;

	if (!av[1])
		sh_print_env(ac, av, ev);
	else if (av[2] && av[3])
		ft_putendl_fd("setenv : Too many arguments.", 2);
	else
	{
		if (!sh_check_var(av[1]))
			ft_putendl_fd("setenv : Variable name must \
				contain alphanumeric characters.", 2);
		else
		{
			if (sh_find_env(av[1], ev))
			{
				sh_var_del(&ev, av[1]);
			}
			str = ft_strjoin(av[1], "=");
			sh_var_add(&ev, str, av[2]);
			free(str);
		}
	}
			return (0);
}
