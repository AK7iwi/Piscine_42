/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 00:36:16 by mfeldman          #+#    #+#             */
/*   Updated: 2022/02/24 14:07:58 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *str, int l)
{
	char	*word;
	int		a;

	word = malloc((l + 1) * sizeof (char));
	a = 0;
	while (a < l)
	{
		word[a] = str[a];
		a++;
	}
	word[l] = '\0';
	return (word);
}

int	separ(char *str, char *charset)
{
	int	a;

	a = 0;
	while (charset[a] != '\0')
	{
		if (str[0] == charset[a])
		{
			return (1);
		}
		a++;
	}
	return (0);
}

int	longm(char *str, char *charset)
{
	int	a;

	a = 0;
	while (str[a] != '\0' && !separ(str + a, charset))
	{
		a++;
	}
	return (a);
}

int	cont(char *str, char *charset)

{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (str[a] != '\0')
	{
		while (str[a] != '\0' && separ(str + a, charset))
		{
			a++;
		}
		if (longm(str + a, charset) > 0)
		{
			b++;
		}
		a += longm(str + a, charset);
	}
	return (b);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		a;
	int		b;

	a = 0;
	b = 0;
	tab = malloc((cont(str, charset) + 1) * sizeof (char *));
	if (tab == 0)
		return (0);
	while (a < cont(str, charset))
	{
		while (str[b] != '\0' && separ(str + b, charset))
			b++;
		tab[a] = ft_strcpy(str + b, longm(str + b, charset));
		b += longm(str + b, charset);
		a++;
	}
	tab[a] = 0;
	return (tab);
}
