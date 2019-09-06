/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_free_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 20:21:28 by thdelmas          #+#    #+#             */
/*   Updated: 2019/03/10 23:40:27 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void	msh_free_cmd(t_cmd **cmd)
{
	t_cmd *tmp;

	if (cmd)
		while (*cmd)
		{
			tmp = (*cmd)->next;
			if ((*cmd)->av)
				msh_free_tab(&((*cmd)->av));
			free(*cmd);
			*cmd = tmp;
		}
}
