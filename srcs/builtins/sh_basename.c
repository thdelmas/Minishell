/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 23:45:07 by thdelmas          #+#    #+#             */
/*   Updated: 2019/06/17 00:07:25 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		sh_basename(int ac, char **av, char **ev)
{
	char	*tmp;
	size_t	i;
	
	i = 0;
	if (ac <= 1 || !av[1])
		return (0);
	tmp = ft_strrchr(av[1], '/');
	while (*tmp == '/' && !tmp[1] && tmp != av[1])
	{
		*tmp = '\0';
		tmp--;
	}
	tmp = ft_strrchr(av[1], '/') + (tmp != av[1]);
	ft_putendl(tmp);
		return (0);
}
