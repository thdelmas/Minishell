/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_create_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:53:44 by thdelmas          #+#    #+#             */
/*   Updated: 2019/07/01 14:56:47 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_param		*sh_create_param(char *key, char *value)
{
	t_param *new;

	if (!(new = (t_param *)malloc(sizeof(t_param))))
		return(NULL);
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}
