/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:18:54 by thdelmas          #+#    #+#             */
/*   Updated: 2018/12/22 20:07:43 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *src, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*dest;
	size_t	n;

	if (!src)
		return (NULL);
	n = 0;
	len = ft_strlen(src);
	if ((dest = (char *)malloc(sizeof(char) * len + 1)))
	{
		dest[len] = 0;
		while (n < len)
		{
			dest[n] = f(n, src[n]);
			n++;
		}
	}
	return (dest);
}
