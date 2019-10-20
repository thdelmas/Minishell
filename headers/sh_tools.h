/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_tools.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:49:33 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/21 00:49:53 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_TOOLS_H
# define SH_TOOLS_H

# include "sh.h"

void	sh_exitpoint(int status)__attribute__((noreturn));
void	sh_read_tty(void);
void	sh_sh_clr(t_sh *shell);

#endif
