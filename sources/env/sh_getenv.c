/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:56:51 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/29 13:57:53 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "libft.h"
#include "sh_env.h"

t_env	*sh_getenv(const char *key)
{
	t_env	*tmp;

	if (!(tmp = sh()->env))
		return (NULL);
	while (tmp && ft_strcmp(tmp->key, key))
		tmp = tmp->next;
	return (tmp);
}
