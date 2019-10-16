/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:49:05 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/16 16:05:16 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "sh_signals.h"
#include "sh_line_edition.h"

int		main(int ac, char **av, char **env)
{
	char	**av_tmp;
	t_sh	*sh;

	sh_handle_signals();
	if (ac == 1)
	{
		sh_init_termcaps();
		sh_read_tty();
	}
	return (0);
}
