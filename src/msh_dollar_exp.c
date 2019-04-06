/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_dollar_exp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 23:09:22 by thdelmas          #+#    #+#             */
/*   Updated: 2019/03/11 14:38:35 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

char			*msh_dollar_exp(t_msh *msh, char *str)
{
	char	*c;
	char	*tmp;
	char	*tmp2;
	char	*next;
	char	**var;

	if (!(c = ft_strchr(str, '$')))
		return (str);
	tmp = ++c;
	while (ft_isalnum(*tmp) || *tmp == '_')
		tmp++;
	tmp2 = ft_strndup(str, c - str - 1);
	next = ft_strdup(tmp);
	tmp = ft_strndup(c, tmp - c);
	c = ft_joinfree(tmp, "=", tmp);
	if ((var = msh_find_env(c, msh->env)))
		if ((tmp = ft_strchr(*var, '=')))
		{
			tmp2 = ft_joinfree(tmp2, tmp + 1, tmp2);
			str = ft_joinfree(tmp2, next, str);
		}
	free(c);
	free(tmp2);
	free(next);
	return (str);
}
