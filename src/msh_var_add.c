/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_tab_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:39:38 by thdelmas          #+#    #+#             */
/*   Updated: 2019/03/10 18:09:38 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static void	msh_var_replace(char ***tab, char *name, char *val)
{
	char	**dest;

	dest = msh_find_env(name, *tab);
	free(*dest);
	*dest = ft_strjoin(name, val);
}

void		msh_var_add(char ***tab, char *name, char *val)
{
	char	**ret;
	char	*tmp;
	int		i;

	if (!*tab)
		return ;
	if ((msh_find_env(name, *tab)))
		return (msh_var_replace(tab, name, val));
	i = 0;
	while ((*tab)[i])
		i++;
	if (!(ret = (char **)malloc(sizeof(char *) * (i + 3))))
		return ;
	i = -1;
	tmp = ft_strjoin(name, val);
	while ((*tab)[++i])
		ret[i] = ft_strdup((*tab)[i]);
	ret[i] = tmp;
	ret[++i] = NULL;
	msh_free_tab(tab);
	*tab = ret;
}
