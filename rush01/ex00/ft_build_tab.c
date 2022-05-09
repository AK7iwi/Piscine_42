/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mede-sou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 09:52:13 by mede-sou          #+#    #+#             */
/*   Updated: 2022/02/13 16:15:55 by mede-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
Recover integers tab empty,list of integers entered in parameters and tab's size 
Insert values of the list inside tab, in the right place
Recover the completed integer tab
*/

int	ft_col_up(int **tab, int *str, int k, int size)
{
	int	col;
	int	row;

	col = 1;
	row = 0;
	while (col < size - 1)
	{
		tab[row][col] = str[k];
		col++;
		k++;
	}
	return (k);
}

int	ft_col_down(int **tab, int *str, int k, int size)
{
	int	col;
	int	row;

	col = 1;
	row = size - 1;
	while (col < size - 1)
	{
		tab[row][col] = str[k];
		col++;
		k++;
	}
	return (k);
}

int	ft_row_left(int **tab, int *str, int k, int size)
{
	int	col;
	int	row;

	col = 0;
	row = 1;
	while (row < size - 1)
	{
		tab[row][col] = str[k];
		row++;
		k++;
	}
	return (k);
}

int	ft_row_right(int **tab, int *str, int k, int size)
{
	int	col;
	int	row;

	col = size - 1;
	row = 1;
	while (row < size - 1)
	{
		tab[row][col] = str[k];
		row++;
		k++;
	}
	return (k);
}

void	ft_fill_tab(int **tab, int *str, int size)
{
	int	k;

	k = ft_col_up(tab, str, 0, size);
	k = ft_col_down(tab, str, k, size);
	k = ft_row_left(tab, str, k, size);
	k = ft_row_right(tab, str, k, size);
}
