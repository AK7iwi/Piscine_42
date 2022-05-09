/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_n_in_tab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mede-sou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:42:57 by mede-sou          #+#    #+#             */
/*   Updated: 2022/02/13 22:00:51 by mede-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_fill_col(int **tab2, int size, int col);
void	ft_fill_row(int **tab2, int size, int row);
void	ft_check_if_n_in_tab(int **tab, int **tab2, int size, int n);

void	ft_check_if_n_in_tab(int **tab, int **tab2, int size, int n)
{
	int	col;
	int	row;

	col = 1;
	row = 1;
	while (row < size - 1)
	{
		col = 1;
		while (col < size - 1)
		{
			if (tab[row][col] == n)
			{
				ft_fill_col(tab2, size, col);
				ft_fill_row(tab2, size, row);
			}
			col++;
		}
		row++;
	}
}

void	ft_fill_row(int **tab2, int size, int row)
{
	int	col;

	col = 0;
	while (col < size - 2)
	{
		tab2[row - 1][col] = 1;
		col++;
	}
}

void	ft_fill_col(int **tab2, int size, int col)
{
	int	row;

	row = 0;
	while (row < size - 2)
	{
		tab2[row][col - 1] = 1;
		row++;
	}
}
