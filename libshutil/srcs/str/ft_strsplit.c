/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:41:35 by thdelmas          #+#    #+#             */
/*   Updated: 2019/03/24 19:45:58 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_split_count(int mode, const char *str, int num, char c)
{
	int i;
	int k;
	int mot;

	i = 0;
	mot = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c || !(str[i]))
			k = 0;
		while ((str[i] == c) && str[i])
			i++;
		if (str[i] && k == 0)
			mot++;
		while (str[i + k] && !(str[i + k] == c))
			k++;
		if (mode == 1 && mot == num)
			return (k);
		else if (mode == 2 && mot == num)
			return (i);
		i += k;
	}
	return (mot);
}

static void	ft_split_strcpy(char *dest, const char *src, char c)
{
	int i;

	i = -1;
	while (src[++i] && src[i] != c)
		dest[i] = src[i];
	dest[i] = '\0';
}

char		**ft_strsplit(const char *str, char c)
{
	char	**tab;
	int		i;
	int		mot;

	i = 1;
	if (!str)
		return (NULL);
	mot = ft_split_count(0, str, 0, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (mot + 1))))
		return (NULL);
	tab[mot] = NULL;
	while (i <= mot)
	{
		tab[i - 1] = ft_strnew(ft_split_count(1, str, i, c));
		ft_split_strcpy(tab[i - 1], str + ft_split_count(2, str, i, c), c);
		i++;
	}
	return (tab);
}
