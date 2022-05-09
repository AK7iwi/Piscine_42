/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:58:13 by mfeldman          #+#    #+#             */
/*   Updated: 2022/02/25 04:33:07 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		a++;
	}
	return (a);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	a;

	a = 0;
	while (src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

int	nb_charac(int size, char **strs, int sep_l)
{
	int	res;
	int	a;

	res = 0;
	a = 0;
	while (a < size)
	{
		res += ft_strlen(strs[a]);
		a++;
	}
	res += sep_l * (size - 1);
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		a;
	int		b;

	if (size == 0)
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	str = malloc((nb_charac(size, strs, ft_strlen(sep)) + 1) * sizeof (char));
	a = 0;
	b = 0;
	ft_strcpy(str + b, strs[a]);
	while (a < size)
	{
		ft_strcpy(str + b, strs[a]);
		b += ft_strlen(strs[a]);
		if (a < size - 1)
		{
			ft_strcpy(str + b, sep);
			b += ft_strlen(sep);
		}
		a++;
	}
	str[b] = '\0';
	return (str);

