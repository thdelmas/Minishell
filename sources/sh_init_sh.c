/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_init_osh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:41:24 by thdelmas          #+#    #+#             */
/*   Updated: 2019/09/10 12:51:11 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osh.h"

static void	sh_init_oshlvl(t_osh *sh)
{
	char	**shlvl;
	char	*tmp;
	char	*tmp2;

	if ((shlvl = sh_find_env("SHLVL", sh->env)))
	{
		tmp = *shlvl;
		tmp2 = ft_itoa(ft_atoi(tmp + 6) + 1);
	}
	else
		tmp2 = ft_strdup("1");
	sh_var_add(&(sh->env), "SHLVL=", tmp2);
	free(tmp2);
}

static void	sh_init_pwd(t_osh *sh)
{
	char	*tmp2;

	if ((tmp2 = ft_strnew(PATH_MAX + 1)))
	{
		tmp2 = getcwd(tmp2, PATH_MAX);
		sh_var_add(&(sh->env), "PWD=", tmp2);
		free(tmp2);
	}
}

static void	sh_init_env(t_osh *sh)
{
	sh_init_pwd(sh);
	sh_init_oshlvl(sh);
}

t_osh		*sh_init_osh(char **env)
{
	t_osh *sh;

	if (!(sh = (t_osh *)malloc(sizeof(t_osh))))
		return (NULL);
	sh->flags = NULL;
	sh->prim_env = sh_tabdup(env);
	sh->env = sh_tabdup(env);
	sh->cmd_begin = NULL;
	sh->cmd = NULL;
	sh_init_env(sh);
	return (sh);
}
