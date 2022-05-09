/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_prog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mede-sou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 09:40:07 by mede-sou          #+#    #+#             */
/*   Updated: 2022/02/13 23:37:08 by mede-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
All functions related to the creation and display of the matrice 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_check_argv(char *str);
int		*ft_start_str(char *src);
int		ft_size_tab(int *str);
int		**ft_init_tab(int nb);
void	ft_fill_tab(int **tab, int *str, int size);
void	ft_put_tab(int **tab, int size);

/*
Check if argv[0] only contains positive numbers
*/

int	ft_check_argv(char *str)
{
	int	i;
	int	nb_space;

	i = 0;
	nb_space = 0;
	while (str[i])
	{
		if ((str[i] < '1' || str[i] > '9') && str[i] != ' ')
			return (0);
		if (str[i] >= '1' && str[i] <= '9' && str[i + 1] >= '1'
			&& str[i + 1] <= '9')
			return (0);
		if (str[i] == ' ')
			nb_space++;
		i++;
	}
	if (nb_space % 2 == 0)
		return (0);
	return (1);
}
/*
Take argv[1] and split the string in order to recover all the numbers. 
The result will be first contained in a tab of characters. 
After, the characters tab be converted in a integers tab.
Return the integers tab.
*/

int	ft_strlen(int *str)
{
	int	a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

int	*ft_start_str(char *src)
{
	int	nb_space;
	int	i;
	int	j;
	int	*dest;

	nb_space = 0;
	i = 0;
	while (src[i])
	{
		if (src[i] == ' ')
			nb_space++;
		i++;
	}
	dest = (int *)malloc(sizeof(*dest) * (nb_space + 2));
	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] != ' ')
			dest[j++] = src[i] - '0';
		i++;
	}
	return (dest);
}

/*
Recover the list of integers, find the size of this list. 
Calculate the root of the size's tab. 
Return the root + 2.
*/

int	ft_size_tab(int *str)
{
	int	nb;
	int	a;

	a = 0;
	if (ft_strlen(str) % 4 == 0)
	{
		nb = ft_strlen(str) / 4;
		while (str[a])
		{
			if (str[a] > nb)
				return (0);
			a++;
		}
		return (nb + 2);
	}
	else
		return (0);
}

/*
Recover the size of the integers tab.
Dynamically allocate the size of the tab with malloc.
Display the tab of integers.
*/

int	**ft_init_tab(int nb)
{
	int	**tab;
	int	i;

	i = 0;
	tab = (int **)malloc(sizeof(**tab) * (nb + nb));
	while (i < (nb + 1))
	{
		tab[i] = (int *)malloc(sizeof(**tab) * (nb + nb));
		i++;
	}
	return (tab);
}
