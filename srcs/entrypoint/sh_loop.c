/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:16:29 by maboye            #+#    #+#             */
/*   Updated: 2019/05/13 19:26:49 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"
#include "libft.h"
#include "sh_env.h"
#include "sh_entrypoint.h"
#include "sh_command_line.h"

int		sh_loop(void)
{
	char	**ln_tab;

	while (42)
	{
		sh_prompt();
		ln_tab = NULL;
		if (!(ln_tab = sh_arguments()) || !*ln_tab)
			break ;
		if (!ft_strncmp("exit", *ln_tab, 4))
			break ;
		if (!ft_strncmp("env", *ln_tab, 3))
			sh_print_env();
		else
			while (*ln_tab)
			{
				sh_entrypoint(*ln_tab);
				ln_tab++;
			}
		ft_tab_strdel(&ln_tab);
	}
	return (1);
}
