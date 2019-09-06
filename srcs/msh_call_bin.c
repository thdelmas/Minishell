/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_call_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:17:19 by thdelmas          #+#    #+#             */
/*   Updated: 2019/09/06 23:39:28 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static char		**msh_path_bin(char **env)
{
	char	*tmp;
	char	**path;
	int		i;

	i = 2;
	if (!(path = msh_find_env("PATH", env)) || !(*path)[5])
		return (NULL);
	tmp = (*path) + 5;
	return (ft_strsplit(tmp, ':'));
}

static void		msh_exec_bin(t_msh *msh, t_cmd *cmd)
{
	pid_t	father;
	int		status;

	msh_var_add(&(msh->env), "_=", cmd->av[0]);
	father = fork();
	if (father > 0)
		wait(&status);
	else if (father == 0)
		execve(cmd->av[0], cmd->av, msh->env);
}

static void		msh_call_bin_sub(t_cmd *cmd, char ***path, char **tmp)
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

void			msh_call_bin(t_msh *msh, t_cmd *cmd)
{
	struct stat	r;
	char		**path;
	char		**path2;
	char		*tmp;

	if (lstat(cmd->av[0], &r) == 0
			&& ((r.st_mode & S_IFMT) != S_IFDIR && (r.st_mode & S_IXUSR)))
		return (msh_exec_bin(msh, cmd));
	else if (!(path = msh_path_bin(msh->env)))
		return ;
	path2 = path;
	msh_call_bin_sub(cmd, &path, &tmp);
	if (*(path) && *tmp && *tmp != '/')
		msh_exec_bin(msh, cmd);
	else if (*tmp)
	{
		ft_putstr(tmp);
		free(tmp);
		ft_putendl(": command not found");
		msh_free_tab(&path2);
		msh_free_tab(&(cmd->av));
		return ;
	}
	msh_free_tab(&path2);
	free(tmp);
}
