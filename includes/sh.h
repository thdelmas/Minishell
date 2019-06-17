/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 00:08:33 by thdelmas          #+#    #+#             */
/*   Updated: 2019/06/17 00:08:36 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH21_H
# define SH21_H

# include "sh_line.h"
# include "sh_env.h"

typedef struct		s_sh
{
	t_env			*env;
	t_ln			*ln_history;
	int				last_cmd_result;
	int				type; //for recognize tokens
}					t_sh;

t_sh	*sh(void);

#endif
