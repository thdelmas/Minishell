/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_call_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:17:19 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/28 20:14:42 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osh.h"

static char		**sh_path_bin(char **env)
{
	char	*tmp;
	char	**path;
	int		i;

	i = 2;
	if (!(path = sh_find_env("PATH", env)) || !(*path)[5])
		return (NULL);
	tmp = (*path) + 5;
	return (ft_strsplit(tmp, ':'));
}

static void		sh_exec_bin(t_osh *sh, t_cmd *cmd)
{
	pid_t	father;
	int		status;

	sh_var_add(&(sh->env), "_=", cmd->av[0]);
	father = fork();
	if (father > 0)
		wait(&status);
	else if (father == 0)
		execve(cmd->av[0], cmd->av, sh->env);
}

static void		sh_call_bin_sub(t_cmd *cmd, char ***path, char **tmp)
{
	struct stat	r;

	*tmp = ft_strdup(cmd->av[0]);
	if (**tmp != '/')
		while (**path && (lstat(cmd->av[0], &r) != 0
					|| (((r.st_mode & S_IFMT) == S_IFDIR
							|| !(r.st_mode & S_IXUSR)))))
		{
			cmd->av[0] = ft_strjoin_free("/", *tmp, cmd->av[0]);
			cmd->av[0] = ft_strjoin_free(*((*path)++), cmd->av[0], cmd->av[0]);
		}
}

void			sh_call_bin(t_osh *sh, t_cmd *cmd)
{
	struct stat	r;
	char		**path;
	char		**path2;
	char		*tmp;

	if (lstat(cmd->av[0], &r) == 0
			&& ((r.st_mode & S_IFMT) != S_IFDIR && (r.st_mode & S_IXUSR)))
		return (sh_exec_bin(sh, cmd));
	else if (!(path = sh_path_bin(sh->env)))
		return ;
	path2 = path;
	sh_call_bin_sub(cmd, &path, &tmp);
	if (*(path) && *tmp && *tmp != '/')
		sh_exec_bin(sh, cmd);
	else if (*tmp)
	{
		ft_putstr(tmp);
		free(tmp);
		ft_putendl(": command not found");
		sh_free_tab(&path2);
		sh_free_tab(&(cmd->av));
		return ;
	}
	sh_free_tab(&path2);
	free(tmp);
}
