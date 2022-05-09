/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:06:40 by mfeldman          #+#    #+#             */
/*   Updated: 2022/02/22 20:37:30 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*tab;
	int	a;
	int	b;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	a = (max - min);
	b = 0;
	tab = (int *)malloc(sizeof (int) * a + 1);
	if (tab == 0)
		return (-1);
	while (b < a)
	{
		tab[b] = min;
		min++;
		b++;
	}
	tab[b] = '\0';
	*range = tab;
	return (b);
}
