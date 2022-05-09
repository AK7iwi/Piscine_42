/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudo_method.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 08:02:52 by agardett          #+#    #+#             */
/*   Updated: 2022/02/13 22:15:06 by mede-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		**ft_init_tab(int nb);
int		ft_sudo_fill(int **tab, int **tab2, int size, int n);
void	ft_free_tab(int **tab, int size);
void	ft_check_if_n_in_tab(int **tab, int **tab2, int size, int n);
void	ft_check_occupation(int **tab, int **tab2, int size);
void	ft_set_tab_zero(int **tab2, int size);
void	ft_put_tab(int **tab, int size);

/*
Solve the table like if it was a classical sudoku using the numbers place by the 
init method. If the the sudo method tested all the nummber without having find 
any number it sould return a 0.
*/

void	ft_sudo_metho(int **tab, int size)
{
	int	**tab2;
	int	n;
	int	modif;

	n = 1;
	modif = 0;
	tab2 = ft_init_tab(size - 2);
	while (n < size - 1)
	{
		ft_check_occupation(tab, tab2, size);
		ft_check_if_n_in_tab(tab, tab2, size, n);
		modif += ft_sudo_fill(tab, tab2, size, n);
		ft_set_tab_zero(tab2, size);
		n++;
	}
	if (modif != 0)
		ft_sudo_metho(tab, size);
	free(tab2);
}
