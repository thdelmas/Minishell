/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_reset_tty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:14:51 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/20 17:38:12 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#include "sh.h"

void	sh_reset_tty()
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, sh()->reset);
}
