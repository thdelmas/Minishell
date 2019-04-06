/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_tabdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:54:04 by thdelmas          #+#    #+#             */
/*   Updated: 2019/03/10 22:18:05 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

char	**msh_tabdup(char **tab)
{
	char	**ret;
	int		i;

	i = 0;
	ret = NULL;
	if (tab)
	{
		while (tab[i])
			i++;
		if (!(ret = (char **)malloc(sizeof(char *) * (i + 1))))
			return (NULL);
		i = -1;
		while (tab[++i])
			ret[i] = ft_strdup(tab[i]);
		ret[i] = NULL;
	}
	return (ret);
}
