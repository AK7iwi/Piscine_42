/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cond_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:51:21 by mfeldman          #+#    #+#             */
/*   Updated: 2022/02/13 23:36:31 by mede-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_check_cond_tabg(int **tab, int size)
{
	int	row;
	int	col;
	int	cont;
	int	max;

	row = 0;
	while (++row < size - 1)
	{
		col = 0;
		cont = 1;
		max = tab[row][1];
		while (++col < size - 1)
		{
			if (max < tab[row][col + 1])
			{
				max = tab[row][col + 1];
				cont++;
			}
		}
		if (cont != tab[row][0])
			return (0);
	}
	return (1);
}

int	ft_check_cond_tabd(int **tab, int size)
{
	int	row;
	int	col;
	int	cont;
	int	max;

	row = 0;
	while (++row < size - 1)
	{
		col = size - 1;
		max = tab[row][size - 2];
		cont = 1;
		while (--col > 0)
		{
			if (max < tab[row][col - 1])
			{
				max = tab[row][col - 1];
				cont++;
			}
		}
		if (cont != tab[row][size - 1])
			return (0);
	}
	return (1);
}

int	ft_check_cond_tabh(int **tab, int size)
{
	int	row;
	int	col;
	int	cont;
	int	max;

	col = 0;
	while (++col < size - 1)
	{
		row = 0;
		max = tab[1][col];
		cont = 1;
		while (++row < size - 1)
		{
			if (max < tab[row + 1][col])
			{
				max = tab[row + 1][col];
				cont++;
			}
		}
		if (cont != tab[0][col])
			return (0);
	}
	return (1);
}

int	ft_check_cond_tabb(int **tab, int size)
{
	int	row;
	int	col;
	int	cont;
	int	max;

	col = 0;
	while (++col < size - 1)
	{
		row = size - 1;
		max = tab[size - 2][col];
		cont = 1;
		while (--row > 0)
		{
			if (max < tab[row - 1][col])
			{
				max = tab[row - 1][col];
				cont++;
			}
		}
		if (cont != tab[size - 1][col])
			return (0);
	}
	return (1);
}

int	ft_check_cond(int **tab, int size)
{
	if (ft_check_cond_tabg(tab, size) && ft_check_cond_tabd(tab,
			size) && ft_check_cond_tabh(tab, size) && ft_check_cond_tabb(tab,
			size))
		return (1);
	return (0);
}
