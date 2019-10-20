/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_set_tty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:08:53 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/21 00:53:45 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#include "sh.h"

void	sh_set_tty()
{
	struct termios	term;
	struct termios	orig;

	tcgetattr(STDIN_FILENO, &orig);
       	sh()->reset = &orig;
	sh()->term = &term;
	term = orig;
	term.c_lflag &= ~(ECHO | ICANON);
	term.c_lflag &= (ISIG);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
