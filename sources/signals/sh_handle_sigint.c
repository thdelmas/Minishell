/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_handle_sigint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:34:20 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/19 16:58:43 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_signals.h"
#include "sh_tools.h"
#include <stdio.h>

void	sh_handle_sigint(int signal)
{
	(void)signal;
	dprintf(2, "\n\nMsh: Signal received: SIGINT\n\n");
	//sh_exitpoint(1);
}
