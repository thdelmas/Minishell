/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:18:48 by thdelmas          #+#    #+#             */
/*   Updated: 2019/03/10 23:41:10 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static void		msh_cd_sub(t_msh *msh, char **pwd, char **np, char *olddir)
{
	if (*(*np) == '-' && (pwd = msh_find_env("OLDPWD", msh->env)) && pwd[0][7])
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
		msh_var_add(&(msh->env), "OLDPWD=", olddir);
		msh_var_add(&(msh->env), "PWD=", *np);
		free(*np);
	}
}

void			msh_cd(t_msh *msh, t_cmd *cmd)
{
	char	**pwd;
	char	*np;
	char	*olddir;

	pwd = msh_find_env("PWD", msh->env);
	if (cmd->av)
	{
		if (!(olddir = ft_strnew(PATH_MAX + 1)))
			return ;
		olddir = getcwd(olddir, PATH_MAX);
		if ((cmd->av)[1])
			np = ft_strdup((cmd->av)[1]);
		else if ((pwd = msh_find_env("HOME=", msh->env)) && pwd[0][5])
			np = ft_strdup(pwd[0] + 5);
		else
		{
			ft_putendl("$HOME not set");
			return ;
		}
		msh_cd_sub(msh, pwd, &np, olddir);
		free(olddir);
	}
}
