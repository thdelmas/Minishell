/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_handle_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:24:57 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/21 00:50:31 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>

#include "sh_signals.h"
#include "sh_tools.h"

static void	sh_signal_error()
{
	dprintf(2 , "An error occurred while setting a signal handler.\n");
	sh_exitpoint(1);
}

void	sh_handle_signals(void)
{
	if (signal(SIGINT, sh_handle_sigint) == SIG_ERR)
		sh_signal_error();
}
