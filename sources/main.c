/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:49:05 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/15 15:40:30 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "sh_signals.h"

int		main(int ac, char **av, char **env)
{
	char	**av_tmp;
	t_sh	*sh;

	sh_handle_signals();
	if (ac == 1)
	{
		if (!(av_tmp = sh_tabdup(av)))
			return (0);
		if (!(sh = sh_init_sh(env)))
			return (0);
		sh_free_tab(&av_tmp);
		sh_loop(sh);
		sh_free_sh(&sh);
	}
	return (0);
}
