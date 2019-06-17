/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:58:56 by thdelmas          #+#    #+#             */
/*   Updated: 2019/06/17 19:35:15 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	sh_check_var(char *str)
{
	str--;
	while (*(++str))
		if (!(ft_isalnum(*(str)) || *str == '_'))
			return (0);
	return (1);
}

void		sh_setenv(t_sh *sh, t_cmd *cmd)
{
	char	*str;

	if (!(cmd->av)[1])
		sh_print_env(sh, cmd);
	else if ((cmd->av)[2] && (cmd->av)[3])
		ft_putendl_fd("setenv : Too many arguments.", 2);
	else
	{
		if (!sh_check_var((cmd->av)[1]))
			ft_putendl_fd("setenv : Variable name must \
				contain alphanumeric characters.", 2);
		else
		{
			if (sh_find_env((cmd->av)[1], sh->env))
			{
				sh_var_del(&(sh->env), (cmd->av)[1]);
			}
			str = ft_strjoin((cmd->av)[1], "=");
			sh_var_add(&(sh->env), str, cmd->av[2]);
			free(str);
		}
	}
}
