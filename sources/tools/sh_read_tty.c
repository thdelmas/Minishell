/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_read_tty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:08:16 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/18 16:35:32 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <curses.h>

#include "libft.h"
#include "sh.h"

void	sh_read_tty()
{
	char	c[4];
	char	*buff;
	int	len;

	buff = NULL;
	ft_bzero(c, 4);
	len = 0;

	while (read(0, c, 1) > 0)
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
