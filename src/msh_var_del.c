/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_tab_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:43:24 by thdelmas          #+#    #+#             */
/*   Updated: 2019/03/10 18:06:51 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void	msh_var_del(char ***tab, char *str)
{
	char	**ret;
	int		i;
	int		j;

	if (!*tab)
		return ;
	i = 0;
	j = 0;
	while ((*tab)[i])
		i++;
	if (!(ret = (char **)malloc(sizeof(char *) * (i + 1))))
		return ;
	i = -1;
	while ((*tab)[++i])
		if (ft_strncmp((*tab)[i], str, ft_strlen(str)))
			ret[j++] = ft_strdup((*tab)[i]);
	ret[j] = NULL;
	msh_free_tab(tab);
	*tab = ret;
}
