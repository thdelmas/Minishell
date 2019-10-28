/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_tools.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:49:33 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/28 21:33:32 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_TOOLS_H
# define SH_TOOLS_H

# include "sh.h"

void	sh_shclr(t_sh *shell);
void	sh_exitpoint(int status)__attribute__((noreturn));
void	sh_init_tty(void);

#endif
