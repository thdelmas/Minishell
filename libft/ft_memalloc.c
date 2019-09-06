/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:29:08 by thdelmas          #+#    #+#             */
/*   Updated: 2019/02/15 16:50:19 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ptr;

	if (size <= 0)
		return (NULL);
	if (!(ptr = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (--size)
		ptr[size] = 0;
	*ptr = 0;
	return ((void*)(ptr));
}
