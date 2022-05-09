/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_track.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:58:47 by agardett          #+#    #+#             */
/*   Updated: 2022/02/13 23:02:47 by mede-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_put_tab(int **tab, int size);

int	ft_check_if_full(int **tab, int size)
{
	int	row;
	int	col;

	row = 1;
	while (row < size - 1)
	{
		col = 1;
		while (col < size - 1)
		{
			if (tab[row][col] == 0)
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

void	ft_tab_cpy(int **tab, int **tabbis, int size)
{
	int	row;
	int	col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			tabbis[row][col] = tab[row][col];
			col++;
		}
		row++;
	}
}

int	ft_check_row(int **tab, int size, int random, int row)
{
	int	col;

	col = 1;
	while (col < size - 1)
	{
		if (tab[row][col] == random)
			return (0);
		col++;
	}
	return (1);
}

int	ft_check_col(int **tab, int size, int random, int col)
{
	int	row;

	row = 1;
	while (row < size - 1)
	{
		if (tab[row][col] == random)
			return (0);
		row++;
	}
	return (1);
}

int	ft_add_random(int **tabbis, int size, int n)
{
	int	row;
	int	col;

	row = 1;
	while (row < size - 1)
	{
		col = 1;
		while (col < size - 1)
		{
			if (tabbis[row][col] == 0)
			{
				tabbis[row][col] = n;
				return (1);
			}
			col++;
		}
		row++;
	}
	return (0);
}
