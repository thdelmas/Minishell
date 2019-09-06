/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:26:59 by thdelmas          #+#    #+#             */
/*   Updated: 2019/03/10 16:14:36 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_return(char *tmp, char *buff, char **line)
{
	char			*n;

	if ((n = ft_strstr(tmp, "\n")))
	{
		buff = ft_strcpy(buff, n + 1);
		*n = '\0';
	}
	*line = ft_strdup(tmp);
	free(tmp);
	if ((*line)[0] || n)
		return (1);
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	int				res;
	char			*tmp;
	char			*n;
	static char		buff[BUFF_SIZE + 1] = {0};

	if (fd < 0 || !line || read(fd, NULL, 0) < 0)
		return (-1);
	if (!(tmp = ft_strdup(buff)))
		return (-1);
	ft_bzero(buff, BUFF_SIZE);
	if ((n = ft_strstr(tmp, "\n")))
		return (ft_return(tmp, buff, line));
	while ((res = read(fd, buff, BUFF_SIZE) > 0))
	{
		n = tmp;
		if (!(tmp = ft_strjoin(tmp, buff)))
			return (-1);
		free(n);
		ft_bzero(buff, BUFF_SIZE);
		if ((n = ft_strstr(tmp, "\n")))
			break ;
	}
	return (ft_return(tmp, buff, line));
}
