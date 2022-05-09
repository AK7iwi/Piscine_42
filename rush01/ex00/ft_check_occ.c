/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_occ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:20:31 by mfeldman          #+#    #+#             */
/*   Updated: 2022/02/13 22:01:25 by mede-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_check_occupation(int **tab, int **tab2, int size);

void	ft_check_occupation(int **tab, int **tab2, int size)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < size - 1)
	{
		j = 1;
		while (j < size - 1)
		{
			if (tab[i][j] > 0 || tab[i][j] > '0')
			{
				tab2[i - 1][j - 1] = 1;
			}
			j++;
		}
		i++;
	}
}
