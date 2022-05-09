/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:48:22 by mfeldman          #+#    #+#             */
/*   Updated: 2022/02/25 00:15:41 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	a;
	int	b;

	if (min >= max)
	{
		return (0);
	}
	a = max - min;
	b = 0;
	range = (int *)malloc(sizeof (int) * a + 1);
	if (range == 0)
		return (0);
	while (b < a)
	{
		range[b] = min;
		min ++;
		b++;
	}
	range[b] = '\0';
	return (range);
}


#include <stdio.h>
int	main(void)
{
	int *range;

	range = ft_range(0, 5);
	printf("0, 1, 2, 3, 6 : %d, %d, %d, %d, %d\n", range[0], range[1], range[2], range[3], range[4]);

	range = ft_range(3, 3);

	range = ft_range(-6, -9);
	printf("-1, 0 : %d, %d", range[0], range[1]);
}
