/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_init_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 22:43:16 by thdelmas          #+#    #+#             */
/*   Updated: 2019/03/10 22:21:16 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static int	msh_empty_ln(char *line)
{
	if (!line)
		return (1);
	while (*line)
	{
		if (*line != ' ' && *line != '\t' && *line != '\n')
			return (0);
		line++;
	}
	return (1);
}

t_cmd		*msh_init_cmd(void)
{
	t_cmd	*cmd;
	char	*line;

	line = NULL;
	while (msh_empty_ln(line))
	{
		if (line)
			free(line);
		msh_prompt();
		if (get_next_line(0, &line) <= 0)
			return (NULL);
	}
	if (!(cmd = (t_cmd *)malloc(sizeof(t_cmd))))
		return (NULL);
	if (!(cmd->av = msh_split_whitespaces(line)))
	{
		ft_putendl("-ERREUR-");
		free(line);
		free(cmd);
		return (NULL);
	}
	ft_putstr("yolo\n");
	free(line);
	cmd->status = 0;
	cmd->next = NULL;
	return (cmd);
}
