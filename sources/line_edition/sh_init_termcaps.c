/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_init_termcaps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:17:33 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/21 00:53:17 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_tools.h"

#include <term.h>
#include <stdlib.h>
#include <stdio.h>

static void sh_termcaps_error(int ret)
{
	if (ret == -1)
		dprintf(2, "Could not access to the termcap database..\n");
	else if (ret == 0)
		dprintf(2, "Terminal type : not available.\n");
	sh_exitpoint(1);
}

void	sh_init_termcaps()
{
	int ret;

	ret = tgetent(NULL, "vt100");
	if (ret < 1)
		sh_termcaps_error(ret);
}
