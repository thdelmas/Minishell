/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_free_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:58:49 by thdelmas          #+#    #+#             */
/*   Updated: 2019/03/03 21:21:04 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void	msh_free_tab(char ***buff)
{
	char **tmp;

	tmp = *buff;
	if (tmp)
		while (*tmp)
		{
			free(*tmp);
			tmp++;
		}
	free(*buff);
	*buff = NULL;
}
