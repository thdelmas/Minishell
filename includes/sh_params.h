/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_params.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:34:10 by thdelmas          #+#    #+#             */
/*   Updated: 2019/07/01 14:37:32 by thdelmas         ###   ########.fr       */
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

#endif
