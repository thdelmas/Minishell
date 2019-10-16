/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_read_tty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:08:16 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/16 22:37:38 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	sh_read_tty()
{
	char	c;
	char	*buff;

	buff = NULL;
	while (read(0, &c, 1) > 0)
	{
		if (c != '\n')
			buff = ft_cjoin_free(buff, c, buff);
		else	
			ft_putendl(buff);
	}
}
