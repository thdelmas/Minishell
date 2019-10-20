/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_read_tty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:08:16 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/21 00:52:33 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <curses.h>
#include <term.h>

#include "libft.h"
#include "sh.h"
#include "sh_line_edition.h"

void	sh_read_tty()
{
	char	c[5];
	char	*buff;
	int	len;
	char	*cl_cap = tgetstr("cl", NULL);

	buff = NULL;
	ft_bzero(c, 5);
	len = 0;
	sh_set_tty();
	while (read(0, c, 1) > 0)
	{
		if (*c == 'q')
			break;
		ft_putnbr_fd((int)*c, 0);
		ft_putchar_fd(' ', 0);
		ft_bzero(c, 5);
	}
	tputs (cl_cap, 1, putchar);
}
