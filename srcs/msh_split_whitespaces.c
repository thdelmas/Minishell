/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_split_whitespaces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdelmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:34:57 by thdelmas          #+#    #+#             */
/*   Updated: 2019/03/10 18:07:40 by thdelmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static int		msh_split_count(int mode, char *str, int num)
{
	int i;
	int k;
	int mot;

	i = 0;
	mot = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || !(str[i]))
			k = 0;
		while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i])
			i++;
		if (str[i] && k == 0)
			mot++;
		while (str[i + k] && !(str[i + k] == 32
					|| str[i + k] == 9 || str[i + k] == 10))
			k++;
		if (mode == 1 && mot == num)
			return (k);
		else if (mode == 2 && mot == num)
			return (i);
		i += k;
	}
	return (mot);
}

static void		msh_split_strcpy(char *dest, char *src)
{
	int i;

	i = -1;
	while (src[++i] && src[i] != 32 && src[i] != 10 && src[i] != 9)
		dest[i] = src[i];
	dest[i] = '\0';
}

char			**msh_split_whitespaces(char *str)
{
	char	**tab;
	int		i;
	int		mot;

	i = 1;
	if (!str)
		return (NULL);
	mot = msh_split_count(0, str, 0);
	if (!(tab = (char**)malloc(sizeof(char*) * (mot + 1))))
		return (NULL);
	tab[mot] = NULL;
	while (i <= mot)
	{
		if (!(tab[i - 1] = ft_strnew(msh_split_count(1, str, i))))
			return (NULL);
		msh_split_strcpy(tab[i - 1], str + msh_split_count(2, str, i));
		i++;
	}
	return (tab);
}
