/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 19:37:37 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/28 21:31:26 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh.h"
#include "sh_tools.h"
#include "sh_errors.h"
#include <stdlib.h>

t_sh	*sh(void)
{
	static t_sh	*s = NULL;

	if (s)
		return (s);
	else if (!(s = (t_sh*)malloc(sizeof(t_sh))))
	{
		ft_putendl_fd(SH_MALLOC_E, STDERR_FILENO);
		exit(1);
	}
	sh_shclr(s);
	return (s);
}
