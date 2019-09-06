/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:58:56 by thdelmas          #+#    #+#             */
/*   Updated: 2019/03/10 23:44:40 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static int	msh_check_var(char *str)
{
	str--;
	while (*(++str))
		if (!(ft_isalnum(*(str)) || *str == '_'))
			return (0);
	return (1);
}

void		msh_setenv(t_msh *msh, t_cmd *cmd)
{
	char	**tmp;
	char	*str;

	tmp = msh->env;
	if (!(cmd->av)[1])
		msh_print_env(msh, cmd);
	else if ((cmd->av)[2] && (cmd->av)[3])
		ft_putendl_fd("setenv : Too many arguments.", 2);
	else
	{
		if (!msh_check_var((cmd->av)[1]))
			ft_putendl_fd("setenv : Variable name must \
				contain alphanumeric characters.", 2);
		else
		{
			if (msh_find_env((cmd->av)[1], msh->env))
			{
				tmp = msh->env;
				msh_var_del(&(msh->env), (cmd->av)[1]);
			}
			str = ft_strjoin((cmd->av)[1], "=");
			msh_var_add(&(msh->env), str, cmd->av[2]);
			free(str);
		}
	}
}
