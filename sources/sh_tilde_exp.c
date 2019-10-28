/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_tilde_exp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 21:00:49 by thdelmas          #+#    #+#             */
/*   Updated: 2019/09/10 13:56:16 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osh.h"

static char		**sh_tilde_exp_sub(t_osh *sh, char *c)
{
	char	**ret;

	if (c[1] == '-' && !(ret = sh_find_env("OLDPWD", sh->env)))
	{
		ft_putendl("OLPDPWD not set");
		return (NULL);
	}
	else if (c[1] == '+' && !(ret = sh_find_env("PWD", sh->env)))
	{
		ft_putendl("PWD not set");
		return (NULL);
	}
	else if (!(ret = sh_find_env("HOME", sh->env)))
	{
		ft_putendl("HOME not set");
		return (NULL);
	}
	return (ret);
}

char			*sh_tilde_exp(t_osh *sh, char *str)
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
	if (!(ret = sh_tilde_exp_sub(sh, c)))
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
