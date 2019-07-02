/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_params.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:34:10 by thdelmas          #+#    #+#             */
/*   Updated: 2019/07/02 20:47:38 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_PARAMS
# define SH_PARAMS

typedef struct		s_param
{
	char			*key;
	char			*value;
	struct s_param	*next;
}					t_param;

t_param	*sh_create_param(char *key, char *value);
t_param	*sh_env_params(char **env);

#endif
