/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:49:05 by thdelmas          #+#    #+#             */
/*   Updated: 2019/03/11 14:29:51 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		main(int ac, char **av, char **env)
{
	char	**av_tmp;
	t_msh	*msh;

	if (ac == 1)
	{
		if (!(av_tmp = msh_tabdup(av)))
			return (0);
		if (!(msh = msh_init_msh(env)))
			return (0);
		msh_free_tab(&av_tmp);
		msh_loop(msh);
		msh_free_msh(&msh);
	}
	return (0);
}
