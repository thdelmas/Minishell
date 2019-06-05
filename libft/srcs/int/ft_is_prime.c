/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 20:27:24 by thdelmas          #+#    #+#             */
/*   Updated: 2018/12/22 20:29:51 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_prime(int nb)
{
	int sqrt;
	int i;

	i = 2;
	sqrt = ft_sqrt(nb);
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	while (i <= sqrt)
	{
		if (!(nb % i))
			return (0);
		i++;
	}
	return (1);
}
