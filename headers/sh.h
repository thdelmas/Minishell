/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:17:09 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/18 16:32:56 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include <termios.h>

typedef struct		s_sh
{
	int		exit;
	struct termios	term;
}			t_sh;

t_sh	*sh(void);
void	constructor(void) __attribute__((constructor));
void	destructor(void) __attribute__((destructor));

#endif
