/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseniak <nseniak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:23:32 by climousi          #+#    #+#             */
/*   Updated: 2022/02/20 17:10:39 by nseniak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

char	*ft_strcpy_2(char *str, int length)
{
	char	*word;
	int		i;

	word = malloc((length + 1) * sizeof(char));
	i = 0;
	while (i < length)
	{
		word[i] = str[i];
		i++;
	}
	word[length] = '\0';
	return (word);
}

int	is_sep(char *str, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (str[0] == charset[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	word_length(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !is_sep(str + i, charset))
	{
		i++;
	}
	return (i);
}

int	nb_words(char *str, char *charset)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && is_sep(str + i, charset))
		{
			i++;
		}
		if (word_length(str + i, charset) > 0)
		{
			res++;
		}
		i += word_length(str + i, charset);
	}
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = malloc((nb_words(str, charset) + 1) * sizeof(char *));
	while (i < nb_words(str, charset))
	{
		while (str[j] != '\0' && is_sep(str + j, charset))
			j++;
		tab[i] = ft_strcpy_2(str + j, word_length(str + j, charset));
		j += word_length(str + j, charset);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
