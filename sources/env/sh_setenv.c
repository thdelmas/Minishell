/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:37:53 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/29 13:51:55 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_env.h"
#include "sh_errors.h"
#include "sh.h"
#include "libft.h"
#include <stdlib.h>


static t_env	*sh_create_param(const char *key)
{
	t_env	*new;

	if (!(new = (t_env *)malloc(sizeof(t_env))))
	{
		ft_putendl_fd(SH_MALLOC_E, STDERR_FILENO);
		exit(1);
	}
	new->key = ft_strdup(key);
	new->value = NULL;
	new->exp = 0;
	new->rdo = 0;
	new->next = NULL;
	return (new);
}

void		sh_setenv(const char *key, const char *value)
{
	t_env	*env;

	if (!key)
		return ;
	if (!(env = sh()->env))
	{
		sh()->env = sh_create_param(key);
		sh()->env->value = ft_strdup(value);
		return ;
	}
	while (env->next && ft_strcmp(env->key, key))
		env = env->next;
	if (!ft_strcmp(env->key, key) && env->rdo)
	{
		ft_putstr_fd(env->key, 2);
		ft_putendl_fd(": rdo variable", 2);
		return ;
	}
	else if (ft_strcmp(env->key, key))
	{
		env->next = sh_create_param(key);
		env = env->next;
	}
	else if (env->value)
		free(env->value);
	env->value = ft_strdup(value);
	return ;
}
