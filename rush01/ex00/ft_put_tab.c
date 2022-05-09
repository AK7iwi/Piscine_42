/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mede-sou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:15:27 by mede-sou          #+#    #+#             */
/*   Updated: 2022/02/13 23:11:20 by mede-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
Recover the integer tab resolved and the size of the tab.
Display the interior of the tab.
*/

void	ft_put_tab(int **tab, int size)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 1;
	while (i < size - 1)
	{
		j = 1;
		while (j < size - 1)
		{
			if (tab[i][j])
			{
				k = tab[i][j] + '0';
				write (1, &k, 1);
				if (j < size - 2)
					write (1, " ", 1);
			}
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
