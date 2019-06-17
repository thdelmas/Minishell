/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_free_sh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 20:16:59 by thdelmas          #+#    #+#             */
/*   Updated: 2019/06/17 19:30:33 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	sh_free_sh(t_sh **sh)
{
	if ((*sh)->flags)
		free(&((*sh)->flags));
	if ((*sh)->prim_env)
		sh_free_tab(&((*sh)->prim_env));
	if ((*sh)->env)
		sh_free_tab(&((*sh)->env));
	if ((*sh)->cmd_begin)
		sh_free_cmd(&((*sh)->cmd_begin));
	free(*sh);
	*sh = NULL;
}
