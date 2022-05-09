/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudo_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:20:03 by agardett          #+#    #+#             */
/*   Updated: 2022/02/13 22:16:36 by mede-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_nb_zero_by_row(int **tab2, int row, int col, int size);
int	ft_sudo_fill_row(int **tab, int **tab2, int size, int n);
int	ft_nb_zero_by_col(int **tab2, int row, int col, int size);
int	ft_sudo_fill_col(int **tab, int **tab2, int size, int n);
int	ft_sudo_fill(int **tab, int **tab2, int size, int n);

/* Check by row */

int	ft_nb_zero_by_row(int **tab2, int row, int col, int size)
{
	int	compteur;

	compteur = 0;
	while (col < size - 2)
	{
		if (tab2[row][col] == 0)
			compteur++;
		col++;
	}
	return (compteur);
}

int	ft_sudo_fill_row(int **tab, int **tab2, int size, int n)
{
	int	row;
	int	col;
	int	compteur;
	int	modif;

	row = 0;
	modif = 0;
	while (row < size - 2)
	{
		col = 0;
		compteur = ft_nb_zero_by_row(tab2, row, col, size);
		if (compteur == 1)
		{
			while (col < size - 2)
			{
				if (tab2[row][col] == 0)
					tab[row + 1][col + 1] = n;
				col++;
			}
			modif = 1;
		}
		row++;
	}
	return (modif);
}

/* Check by col */

int	ft_nb_zero_by_col(int **tab2, int row, int col, int size)
{
	int	compteur;

	compteur = 0;
	while (row < size - 2)
	{
		if (tab2[row][col] == 0)
			compteur++;
		row++;
	}
	return (compteur);
}

int	ft_sudo_fill_col(int **tab, int **tab2, int size, int n)
{
	int	row;
	int	col;
	int	compteur;
	int	modif;

	col = 0;
	modif = 0;
	while (col < size - 2)
	{
		row = 0;
		compteur = ft_nb_zero_by_col(tab2, row, col, size);
		if (compteur == 1)
		{
			while (row < size - 2)
			{
				if (tab2[row][col] == 0)
					tab[row + 1][col + 1] = n;
				row++;
			}
			modif = 1;
		}
		col++;
	}
	return (modif);
}

/* main sudo fill */

int	ft_sudo_fill(int **tab, int **tab2, int size, int n)
{
	int	modifrow;
	int	modifcol;

	modifrow = 0;
	modifcol = 0;
	modifrow = ft_sudo_fill_row(tab, tab2, size, n);
	if (modifrow != 0 || modifcol != 0)
		return (1);
	else
		return (0);
}
