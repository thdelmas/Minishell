/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:49:05 by thdelmas          #+#    #+#             */
/*   Updated: 2019/07/07 17:27:39 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "libft.h"
#include "libshutil.h"

int		main(int ac, char **av, char **ev)
{
	ft_putendl("Minishell: main.c\n---");
	sh_entrypoint(ac, av, ev);
	
	sh_set(ac, av, &(sh()->env));
	//sh_loop();
	
	
	sh_exitpoint();
	return (0);
}
