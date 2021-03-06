/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:15:11 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/29 14:00:00 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_ENV_H
# define SH_ENV_H

typedef struct		s_env
{
	char		*key;
	char		*value;
	char		exp;
	char		rdo;
	struct	s_env	*next;
}			t_env;

void	sh_setenv(const char *key, const char *value);
void	sh_unsetenv(const char *key);
t_env	*sh_getenv(const char *key);

#endif
