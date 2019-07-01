/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_startup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:00:00 by thdelmas          #+#    #+#             */
/*   Updated: 2019/06/30 17:06:10 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh.h"

void	sh_startup(int ac, char **av, char **ev)
{
	int i;

	i = -1;
	ft_putendl("Minishell: startup.c\n---");
	sh()->ev = ev;
	while (sh()->ev[++i])
		ft_putendl(sh()->ev[i]);
}
