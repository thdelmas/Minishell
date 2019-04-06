/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_init_msh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:41:24 by thdelmas          #+#    #+#             */
/*   Updated: 2019/03/10 22:20:54 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static void	msh_init_shlvl(t_msh *msh)
{
	char	**shlvl;
	char	*tmp;
	char	*tmp2;

	if ((shlvl = msh_find_env("SHLVL", msh->env)))
	{
		tmp = *shlvl;
		tmp2 = ft_itoa(ft_atoi(tmp + 6) + 1);
	}
	else
		tmp2 = ft_strdup("1");
	msh_var_add(&(msh->env), "SHLVL=", tmp2);
	free(tmp2);
}

static void	msh_init_pwd(t_msh *msh)
{
	char	*tmp2;

	if ((tmp2 = ft_strnew(PATH_MAX + 1)))
	{
		tmp2 = getcwd(tmp2, PATH_MAX);
		msh_var_add(&(msh->env), "PWD=", tmp2);
		free(tmp2);
	}
}

static void	msh_init_env(t_msh *msh)
{
	msh_init_pwd(msh);
	msh_init_shlvl(msh);
}

t_msh		*msh_init_msh(char **env)
{
	t_msh *msh;

	if (!(msh = (t_msh *)malloc(sizeof(t_msh))))
		return (NULL);
	msh->flags = NULL;
	msh->prim_env = msh_tabdup(env);
	msh->env = msh_tabdup(env);
	msh->cmd_begin = NULL;
	msh->cmd = NULL;
	msh_init_env(msh);
	return (msh);
}
