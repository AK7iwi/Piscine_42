/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:51:05 by agardett          #+#    #+#             */
/*   Updated: 2022/02/13 23:35:36 by mede-sou         ###   ########.fr       */
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
void	ft_init_method(int **tab, int size);
void	ft_sudo_metho(int **tab, int size);
int		ft_check_cond(int **tab, int size);
int		ft_check_if_full(int **tab, int size);
void	ft_tab_cpy(int **tab, int **tabbis, int size);
int		ft_add_random(int **tabbis, int size, int random);
void	ft_set_tab_zero(int **tab2, int size);

int	ft_print_result(int **tab, int size, int controle)
{
	if (ft_check_cond(tab, size) && controle == 0)
	{
		ft_put_tab(tab, size);
		free(tab);
		return (1);
	}
	return (0);
}

int	**ft_one_line(int **tab, int size)
{
	int	**tabbis;

	tabbis = ft_init_tab(size);
	ft_tab_cpy(tab, tabbis, size);
	return (tabbis);
}

void	ft_resolution(int **tab, int *lint, int size, int check)
{
	int	**tabbis;
	int	random;
	int	controle;

	random = -1;
	controle = 0;
	while (check == 1)
	{
		if (++random == size - 2)
			random = 0;
		ft_sudo_metho(tab, size);
		if (ft_print_result(tab, size, controle))
			check = 0;
		else if (!ft_check_if_full(tab, size) && controle < size - 2)
		{
			tabbis = ft_one_line(tab, size);
			if (ft_add_random(tabbis, size, random))
			{
				controle++;
				ft_resolution(tabbis, lint, size, check);
			}
		}
		else
			check = 0;
	}
}

void	ft_main2(int *lint, int size)
{
	int	**tab;
	int	check;

	check = 1;
	if (size != 0)
	{
		tab = ft_init_tab(size);
		ft_fill_tab(tab, lint, size);
		ft_init_method(tab, size);
		ft_resolution(tab, lint, size, check);
	}
	else
		write(1, "Error\n", 6);
	free(lint);
}

int	main(int argc, char **argv)
{
	int	size;
	int	*lint;

	if (argc == 2)
	{
		if (ft_check_argv(argv[1]))
		{
			lint = ft_start_str(argv[1]);
			size = ft_size_tab(lint);
			ft_main2(lint, size);
		}
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
