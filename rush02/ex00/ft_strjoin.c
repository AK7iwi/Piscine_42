/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseniak <nseniak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:40:54 by climousi          #+#    #+#             */
/*   Updated: 2022/02/20 18:10:19 by nseniak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	nb_charac(int size, char **strs, int sep_length)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (i < size)
	{
		res += ft_strlen(strs[i]);
		i++;
	}
	res += sep_length * (size - 1);
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		index_str;
	int		j;

	if (size == 0)
		return ("");
	if (size == 1)
		return (strs[0]);
	str = malloc((nb_charac(size, strs, ft_strlen(sep)) + 1) * sizeof(char));
	index_str = 0;
	j = 0;
	ft_strcpy(str + j, strs[index_str]);
	while (index_str < size)
	{
		ft_strcpy(str + j, strs[index_str]);
		j += ft_strlen(strs[index_str]);
		if (index_str < size - 1)
		{
			ft_strcpy(str + j, sep);
			j += ft_strlen(sep);
		}
		index_str++;
	}
	str[j] = '\0';
	return (str);
}
