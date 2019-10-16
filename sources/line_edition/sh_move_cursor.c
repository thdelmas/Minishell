/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_move_cursor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:32:52 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/16 14:52:00 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_line_edition.h"
#include "libft.h"
#include <term.h>
#include <stdlib.h>
#include <unistd.h>

void	sh_move_cursor(int x, int y)
{
	char *cm_cap;

	cm_cap = tgetstr("cm", NULL);
	tputs(tgoto(cm_cap, x, y), 10, (int (*)(int))ft_putchar);
}
