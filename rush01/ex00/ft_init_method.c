/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_method.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 08:00:00 by agardett          #+#    #+#             */
/*   Updated: 2022/02/13 22:02:39 by mede-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_check_argv(char *str);
int		*ft_start_str(char *src);
int		ft_size_tab(int *str);
int		**ft_init_tab(int nb);
void	ft_fill_tab(int **tab, int *str, int size);
void	ft_put_tab(int **tab, int size);
void	ft_free_tab(int **tab, int size);
void	ft_init_method(int **tab, int size);

/*
Place all the numbers we can easily guess from the sight line informations
*/

void	ft_check_row_right(int **tab, int size)
{
	int	row;
	int	col;
	int	i;

	row = 1;
	while (row < (size - 1))
	{
		col = size - 1;
		if (tab[row][col] == size - 2)
		{
			i = 1;
			while (col - 1 > 0)
				tab[row][col-- - 1] = i++;
		}
		if (tab[row][size - 1] == 1 && tab[row][0] == 2)
			tab[row][1] = size - 3;
		if (tab[row][size - 1] == 1)
			tab[row][size - 2] = size - 2;
		if (tab[row][size - 1] == size - 3 && tab[row][0] == 2)
			tab[row][2] = size - 2;
		row++;
	}
}

void	ft_check_row_left(int **tab, int size)
{
	int	row;
	int	col;
	int	i;

	row = 1;
	while (row < (size - 1))
	{
		col = 0;
		if (tab[row][col] == size - 2)
		{
			i = 1;
			while (col + 1 < size - 1)
				tab[row][col++ + 1] = i++;
		}
		if (tab[row][0] == 1 && tab[row][size - 1] == 2)
			tab[row][size - 2] = size - 3;
		if (tab[row][0] == 1)
			tab[row][1] = size - 2;
		if (tab[row][0] == size - 3 && tab[row][size - 1] == 2)
			tab[row][size - 3] = size - 2;
		row++;
	}
}

void	ft_check_col_down(int **tab, int size)
{
	int	row;
	int	col;
	int	i;

	col = 1;
	while (col < (size - 1))
	{
		row = size - 1;
		if (tab[row][col] == size - 2)
		{
			i = 1;
			while ((row - 1) > 0)
				tab[row-- - 1][col] = i++;
		}
		if (tab[size - 1][col] == 1 && tab[0][col] == 2)
			tab[1][col] = size - 3;
		if (tab[size - 1][col] == 1)
			tab[size - 2][col] = size - 2;
		if (tab[size - 1][col] == size - 3 && tab[0][col] == 2)
			tab[2][col] = size - 2;
		col++;
	}
}

void	ft_check_col_up(int **tab, int size)
{
	int	row;
	int	col;
	int	i;

	col = 1;
	while (col < (size - 1))
	{
		row = 0;
		if (tab[row][col] == size - 2)
		{
			i = 1;
			while ((row + 1) < (size - 1))
				tab[row++ + 1][col] = i++;
		}
		if (tab[0][col] == 1 && tab[size - 1][col] == 2)
			tab[size - 2][col] = size - 3;
		if (tab[0][col] == 1)
			tab[1][col] = size - 2;
		if (tab[0][col] == size - 3 && tab[size - 1][col] == 2)
			tab[size - 3][col] = size - 2;
		col++;
	}
}

void	ft_init_method(int **tab, int size)
{
	ft_check_col_up(tab, size);
	ft_check_col_down(tab, size);
	ft_check_row_left(tab, size);
	ft_check_row_right(tab, size);
}
