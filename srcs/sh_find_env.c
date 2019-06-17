/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_find_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:45:17 by thdelmas          #+#    #+#             */
/*   Updated: 2019/06/17 19:29:18 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	**sh_find_env(char *name, char **env)
{
	while (*env)
	{
		if (!ft_strncmp(*env, name, ft_strlen(name)))
		{
			return (env);
		}
		env++;
	}
	return (NULL);
}
