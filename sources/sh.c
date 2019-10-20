/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:12:18 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/21 00:49:06 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "sh.h"
#include "sh_tools.h"

t_sh	*sh()
{
	static t_sh	*s = NULL;
	
	if ((s = (t_sh *)malloc(sizeof(t_sh))))
		sh_sh_clr(s);
	return (s);
}
