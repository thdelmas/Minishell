/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:56:45 by thdelmas          #+#    #+#             */
/*   Updated: 2018/11/09 21:14:30 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while ((*s == ' ' || *s == '\t' || *s == '\n') && *s)
		s++;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			j++;
		else
			j = 0;
		i++;
	}
	return (ft_strndup(s, ft_strlen(s) - j));
}
