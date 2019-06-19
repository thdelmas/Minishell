/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 20:24:09 by thdelmas          #+#    #+#             */
/*   Updated: 2018/12/22 20:29:47 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_factorial(int nb)
{
	if (nb == 0)
		return (1);
	else if (nb > 0 && nb <= 12)
		return (nb * ft_factorial(nb - 1));
	else
		return (0);
}
