/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:15:11 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/28 21:29:11 by thdelmas         ###   ########.fr       */
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

#endif
