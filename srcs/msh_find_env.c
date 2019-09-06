/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_find_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:45:17 by thdelmas          #+#    #+#             */
/*   Updated: 2019/03/06 16:58:36 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

char	**msh_find_env(char *name, char **env)
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
