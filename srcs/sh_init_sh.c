/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_init_sh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:41:24 by thdelmas          #+#    #+#             */
/*   Updated: 2019/09/10 12:51:11 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	sh_init_shlvl(t_sh *sh)
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

static void	sh_init_pwd(t_sh *sh)
{
	char	*tmp2;

	if ((tmp2 = ft_strnew(PATH_MAX + 1)))
	{
		tmp2 = getcwd(tmp2, PATH_MAX);
		sh_var_add(&(sh->env), "PWD=", tmp2);
		free(tmp2);
	}
}

static void	sh_init_env(t_sh *sh)
{
	sh_init_pwd(sh);
	sh_init_shlvl(sh);
}

t_sh		*sh_init_sh(char **env)
{
	t_sh *sh;

	if (!(sh = (t_sh *)malloc(sizeof(t_sh))))
		return (NULL);
	sh->flags = NULL;
	sh->prim_env = sh_tabdup(env);
	sh->env = sh_tabdup(env);
	sh->cmd_begin = NULL;
	sh->cmd = NULL;
	sh_init_env(sh);
	return (sh);
}
