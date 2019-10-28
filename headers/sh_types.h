/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:37:28 by thdelmas          #+#    #+#             */
/*   Updated: 2019/10/28 21:01:38 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_TYPES_H
# define SH_TYPES_H

typedef	struct		s_cmd
{
	char			**av;
	int				status;
	struct s_cmd	*next;
}					t_cmd;


typedef struct		s_osh
{
	//OLD
	char	*flags;
	char	**prim_env;
	char	**env;
	t_cmd	*cmd_begin;
	t_cmd	*cmd;
}					t_osh;

#endif
