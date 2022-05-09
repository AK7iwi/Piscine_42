/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:44:44 by mfeldman          #+#    #+#             */
/*   Updated: 2022/02/23 00:53:19 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{	
	int	*a;
	int	*b;
	b = tab;
	a = tab + size;
	while (a != b)
	{
		*a = *tab;
		a--;
		tab++;
	}
}

#include <stdio.h>

int		main(void)
{
	int tab[9] = {0,1,2,3,4,5,6,7,8};

	ft_rev_int_tab(tab, 9);
	printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5], tab[6], tab[7], tab[8], tab[9]);
}
