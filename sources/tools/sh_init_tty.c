/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_init_tty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:18:52 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/28 20:59:22 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_tools.h"
#include "libft.h"

#include <unistd.h>

void	sh_init_tty()
{
	if (!isatty(STDIN_FILENO))
	{
		ft_putendl_fd("Not a TTY", STDERR_FILENO);
		sh_exitpoint(1);
	}
}
