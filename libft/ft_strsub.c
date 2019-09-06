/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:15:33 by thdelmas          #+#    #+#             */
/*   Updated: 2018/11/09 21:16:13 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *src, unsigned int start, size_t len)
{
	char *dest;

	if (!src)
		return (NULL);
	if ((dest = ft_strnew(len)))
	{
		ft_strcpy(dest, src + start);
		dest[len] = 0;
	}
	return (dest);
}
