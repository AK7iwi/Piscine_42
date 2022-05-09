/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_tab_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mede-sou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 09:52:13 by mede-sou          #+#    #+#             */
/*   Updated: 2022/02/13 21:57:48 by mede-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Set the tab at zero everywhere. 
*/

void	ft_set_tab_zero(int **tab2, int size)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (row < size - 2)
	{
		col = 0;
		while (col < size - 2)
		{
			tab2[row][col] = 0;
			col++;
		}
		row++;
	}
}
