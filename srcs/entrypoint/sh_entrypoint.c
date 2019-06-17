/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_entrypoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:10:48 by thdelmas          #+#    #+#             */
/*   Updated: 2019/06/03 23:20:15 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"
#include "21sh.h"
#include "sh_command_line.h"
#include "sh_tokenizer.h"

void	sh_entrypoint(const char *input)
{
	t_token *tok;

	ft_putstr("INPUT: ");
	if (input)
	{
		ft_putendl(input);
		tok = sh_tokenizer(input);
		if (tok)
			print_all_tokens(tok, 0);
	}
	return ;
}
