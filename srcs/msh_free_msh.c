/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_free_msh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 20:16:59 by thdelmas          #+#    #+#             */
/*   Updated: 2019/03/10 16:25:22 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void	msh_free_msh(t_msh **msh)
{
	if ((*msh)->flags)
		free(&((*msh)->flags));
	if ((*msh)->prim_env)
		msh_free_tab(&((*msh)->prim_env));
	if ((*msh)->env)
		msh_free_tab(&((*msh)->env));
	if ((*msh)->cmd_begin)
		msh_free_cmd(&((*msh)->cmd_begin));
	free(*msh);
	*msh = NULL;
}
