/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_handle_sigint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:34:20 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/15 15:36:28 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_signals.h"
#include "sh_tools.h"
#include <stdio.h>

void	sh_handle_sigint(int signal)
{
	dprintf(2, "\nMSH /!\\ SIGINT: %d\n", signal);
	sh_exitpoint(1);
}
