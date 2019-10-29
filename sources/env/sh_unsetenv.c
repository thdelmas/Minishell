/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:55:03 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/29 14:08:12 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "sh_env.h"
#include "libft.h"
#include <stdlib.h>

void	sh_unsetenv(const char *key)
{
	t_env	**env;
	t_env	*tgt;
	t_env	*tmp;

	tgt = NULL;
	tmp = NULL;
	if (!(env = &(sh()->env)) || !*env)
		return ;
	if (!(tgt = sh_getenv(key)))
		return ;
	if (tgt == *env)
		*env = tgt->next;
	else
	{
		tmp = *env;
		while (tmp && tmp->next != tgt)
			tmp = tmp->next;
		if (tmp->next == tgt)
			tmp->next = tgt->next;
	}
	ft_strdel(&(tgt->key));
	ft_strdel(&(tgt->value));
	free(tgt);
}
