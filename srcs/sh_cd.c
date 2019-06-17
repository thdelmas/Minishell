/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:18:48 by thdelmas          #+#    #+#             */
/*   Updated: 2019/06/17 20:27:54 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		sh_cd_sub(char ***ev, char **pwd, char **np, char *olddir)
{
	if (*(*np) == '-' && (pwd = sh_find_env("OLDPWD", *ev)) && pwd[0][7])
	{
		free(*np);
		*np = ft_strdup(*pwd + 7);
	}
	else if ((*np)[0] == '-' && !pwd)
	{
		ft_putendl("$OLDPWD not set");
		return ;
	}
	if (chdir(*np))
	{
		ft_putstr("cd: can't access: ");
		ft_putendl(*np);
		free(*np);
	}
	else
	{
		free(*np);
		if ((*np = ft_strnew(PATH_MAX + 1)))
			*np = getcwd(*np, PATH_MAX);
		sh_var_add(ev, "OLDPWD=", olddir);
		sh_var_add(ev, "PWD=", *np);
		free(*np);
	}
}

int			sh_cd(int ac, char **av, char **ev)
{
	char	**pwd;
	char	*np;
	char	*olddir;

	pwd = sh_find_env("PWD", ev);
	if (av)
	{
		if (!(olddir = ft_strnew(PATH_MAX + 1)))
			return (1);
		olddir = getcwd(olddir, PATH_MAX);
		if (av[1])
			np = ft_strdup(av[1]);
		else if ((pwd = sh_find_env("HOME=", ev)) && pwd[0][5])
			np = ft_strdup(pwd[0] + 5);
		else
		{
			ft_putendl("$HOME not set");
			return (1);
		}
		sh_cd_sub(&ev, pwd, &np, olddir);
		free(olddir);
	}
	return (0);
}
