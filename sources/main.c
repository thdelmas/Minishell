/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:49:05 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/21 00:47:32 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "sh_tools.h"
#include "sh_signals.h"
#include "sh_line_edition.h"

int		main(int ac, char **av, char **ev)
{
	(void)ac;
	(void)av;
	(void)ev;
	sh_handle_signals();
	if (ac == 1)
	{
		sh_init_termcaps();
		sh_read_tty();
	}
	return (0);
}
