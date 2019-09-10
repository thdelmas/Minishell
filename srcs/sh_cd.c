/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:18:48 by thdelmas          #+#    #+#             */
/*   Updated: 2019/09/10 12:48:05 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		sh_cd_sub(t_sh *sh, char **pwd, char **np, char *olddir)
{
	if (*(*np) == '-' && (pwd = sh_find_env("OLDPWD", sh->env)) && pwd[0][7])
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
		sh_var_add(&(sh->env), "OLDPWD=", olddir);
		sh_var_add(&(sh->env), "PWD=", *np);
		free(*np);
	}
}

void			sh_cd(t_sh *sh, t_cmd *cmd)
{
	char	**pwd;
	char	*tmp;
	char	*np;
	char	*olddir;

	pwd = sh_find_env("PWD", sh->env);
	tmp = *pwd;
	if (cmd->av)
	{
		if (!(olddir = ft_strnew(PATH_MAX + 1)))
			return ;
		olddir = getcwd(olddir, PATH_MAX);
		if ((cmd->av)[1])
			np = ft_strdup((cmd->av)[1]);
		else if ((pwd = sh_find_env("HOME=", sh->env)) && pwd[0][5])
			np = ft_strdup(pwd[0] + 5);
		else
		{
			ft_putendl("$HOME not set");
			return ;
		}
		sh_cd_sub(sh, pwd, &np, olddir);
		free(olddir);
	}
}
