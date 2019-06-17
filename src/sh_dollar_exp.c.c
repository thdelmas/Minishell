/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_dollar_exp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 23:09:22 by thdelmas          #+#    #+#             */
/*   Updated: 2019/06/17 19:27:58 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char			*sh_dollar_exp(t_sh *sh, char *str)
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
	c = ft_strjoin_free(tmp, "=", tmp);
	if ((var = sh_find_env(c, sh->env)))
		if ((tmp = ft_strchr(*var, '=')))
		{
			tmp2 = ft_strjoin_free(tmp2, tmp + 1, tmp2);
			str = ft_strjoin_free(tmp2, next, str);
		}
	free(c);
	free(tmp2);
	free(next);
	return (str);
}
