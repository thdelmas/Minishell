/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-ram <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 02:47:34 by ede-ram           #+#    #+#             */
/*   Updated: 2019/07/11 02:49:34 by ede-ram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libshutil.h"
#include "libft.h"
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int		sh_find_error(char *path, char c, int *error)
{
	struct stat	s;
	int			mode;

	mode = F_OK | X_OK;
	if (stat(path, &s) == -1)
	{
		*error = ENOENT;
		return (0);
	}
	if (c != '\0' && (s.st_mode & S_IFDIR) != S_IFDIR)
	{
		*error = ENOTDIR;
		return (0);
	}
	if (c != '\0' && access(path, mode) == -1)
	{
		*error = EACCES;
		return (0);
	}
	return (1);
}

int		sh_check_path(char *all_path, int *error)
{
	char	*path;
	int		i;

	i = 0;
	if (!(path = malloc(sizeof(char) * ft_strlen(all_path) + 1)))
		exit(-1);
	while (all_path[i])
	{
		while (all_path[i] && all_path[i] != '/')
		{
			path[i] = all_path[i];
			i++;
		}
		path[i] = '\0';
		if (!(sh_find_error(path, all_path[i], error)))
		{
			path[i] = '1';
			free(path);
			return (0);
		}
		path[i] = all_path[i];
		i++;
	}
	free(path);
	return (1);
}
