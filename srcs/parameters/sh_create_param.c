/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_create_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:53:44 by thdelmas          #+#    #+#             */
/*   Updated: 2019/07/07 17:44:42 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_env.h"
#include "libft.h"
#include <stdlib.h>

t_env		*sh_create_param(char *key, char *value)
{
	t_env *new;

	if (!(new = (t_env *)malloc(sizeof(t_env))))
		return(NULL);
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}