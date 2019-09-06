/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:19:58 by thdelmas          #+#    #+#             */
/*   Updated: 2018/11/09 21:20:14 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *src, char (*f)(char))
{
	size_t	len;
	char	*dest;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	if ((dest = (char *)malloc(sizeof(char) * (len + 1))))
	{
		dest[len] = 0;
		while (len--)
			dest[len] = f(src[len]);
	}
	return (dest);
}
