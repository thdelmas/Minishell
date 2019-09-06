/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 22:44:00 by thdelmas          #+#    #+#             */
/*   Updated: 2019/03/10 22:56:32 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinfree(const char *s1, const char *s2, char *to_free)
{
	char *tmp;

	tmp = ft_strjoin(s1, s2);
	free(to_free);
	return (tmp);
}
