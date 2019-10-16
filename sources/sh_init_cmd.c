/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_init_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 22:43:16 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/16 14:52:11 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "get_next_line.h"

static int	sh_empty_ln(char *line)
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

t_cmd		*sh_init_cmd(void)
{
	t_cmd	*cmd;
	char	*line;

	line = NULL;
	while (sh_empty_ln(line))
	{
		if (line)
			free(line);
		sh_prompt();
		if (get_next_line(0, &line) <= 0)
			return (NULL);
	}
	if (!(cmd = (t_cmd *)malloc(sizeof(t_cmd))))
		return (NULL);
	if (!(cmd->av = sh_split_whitespaces(line)))
	{
		ft_putendl("-ERREUR-");
		free(line);
		free(cmd);
		return (NULL);
	}
	free(line);
	cmd->status = 0;
	cmd->next = NULL;
	return (cmd);
}
