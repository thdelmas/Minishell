/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:42:32 by thdelmas          #+#    #+#             */
/*   Updated: 2019/07/01 14:53:36 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_params.h"

t_param		*sh_env_params(char **env)
{
	char	*s1;
	size_t	i;
	t_param	params;

	s1 = NULL;
	if (*env)
	{
		i = ft_strclen(*ev, '=');
		s1 = ft_strndup(*ev, i);
		params = sh_create_param(s1, *env + i + 1);
		free(s1);
		params->next = sh_env_params(env + 1);
		return (params);
	}
	else
		return (NULL);
}

