/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_tilde_exp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 21:00:49 by thdelmas          #+#    #+#             */
/*   Updated: 2019/03/10 22:38:10 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static char		**msh_tilde_exp_sub(t_msh *msh, char *c)
{
	char	**ret;

	if (c[1] == '-' && !(ret = msh_find_env("OLDPWD", msh->env)))
	{
		ft_putendl("OLPDPWD not set");
		return (NULL);
	}
	else if (c[1] == '+' && !(ret = msh_find_env("PWD", msh->env)))
	{
		ft_putendl("PWD not set");
		return (NULL);
	}
	else if (!(ret = msh_find_env("HOME", msh->env)))
	{
		ft_putendl("HOME not set");
		return (NULL);
	}
	return (ret);
}

char			*msh_tilde_exp(t_msh *msh, char *str)
{
	char	*c;
	char	*tmp;
	char	*tmp2;
	char	*next;
	char	**ret;

	if (!str || !(c = ft_strchr(str, '~')))
		return (str);
	tmp = ft_strndup(str, c - str);
	next = (c[1] == '-' || c[1] == '+') ? c + 1 : c;
	if (!(ret = msh_tilde_exp_sub(msh, c)))
		return (str);
	tmp2 = ft_strdup(ft_strchr(*ret, '=') + 1);
	c = ft_strjoin(tmp, tmp2);
	free(tmp);
	free(tmp2);
	tmp = ft_strjoin(c, next + 1);
	free(c);
	free(str);
	return (tmp);
}
