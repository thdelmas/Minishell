/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_read_tty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:08:16 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/19 19:14:38 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <curses.h>

#include "libft.h"
#include "sh.h"


/*#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

struct termios orig_termios;

void disableRawMode()
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode()
{
	tcgetattr(STDIN_FILENO, &orig_termios);
   	struct termios raw = orig_termios;
	raw.c_lflag &= ~(ICANON);
	raw.c_lflag &= ~(ECHO);
	raw.c_lflag &= ISIG;
	raw.c_cc[VMIN] = 1;
	raw.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {
	char c;

	enableRawMode();
	while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q')
		write(0, &c, 1);
	disableRawMode();
	return 0;
}
*/
void	sh_read_tty()
{
	char	c[5];
	char	*buff;
	int	len;

	buff = NULL;
	ft_bzero(c, 5);
	len = 0;
	tcgetattr(0, &(sh()->term));
	sh()->term.c_lflag &= ~(ECHO | ICANON);
	sh()->term.c_cc[VMIN] = 1;
	tcsetattr(0, TCSADRAIN, &(sh()->term));
	while (read(0, c, 1) >= 0)
	{
		if (*c != '\n')
			buff = ft_cjoin_free(buff, *c, buff);
		else
		{
			len = ft_strlen(buff);
			if (len >= 3)
			{
				c[0] = buff[len - 3];
				printf("%c %d\n", c[0], (int)c[0]);
			}
			if (len >= 2)
			{
				c[1] = buff[len - 2];
				printf("%c %d\n", c[1], (int)c[1]);
			}
			if (len >= 1)
			{
				c[2] = buff[len - 1];
				printf("%c %d\n", c[2], (int)c[2]);
			}
		}
		ft_bzero(c, 4);
	}
}
