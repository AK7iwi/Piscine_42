/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dissection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseniak <nseniak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:29:03 by nseniak           #+#    #+#             */
/*   Updated: 2022/02/20 18:26:20 by nseniak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

char	*special_cases_2(int nb, int size, char **tab, int add_one)
{
	int		n;
	char	**array;

	array = malloc(2 * sizeof(*tab));
	if (size <= 2)
		n = nb % 10;
	else if (size == 3)
		n = nb % 100;
	else if (size % 3 == 1)
		n = nb - power(10, size - 1);
	if (size == 4)
		add_one = 1;
	array[0] = create_string_recur(nb - n, tab, 0);
	array[1] = create_string_recur(n, tab, add_one);
	return (ft_strjoin(2, array, " "));
}

char	*special_cases(unsigned int nb, int i, char **tab, int add_one)
{
	int		n;
	int		size;
	char	**array;

	size = number_digits(nb);
	array = malloc(2 * sizeof(*tab));
	if (i != 1 && (size % 3 == 1 || size == 3))
	{
		n = nb - (i - 1) * power(10, size - 1);
		array[0] = parse(i, tab);
		array[1] = create_string_recur(n, tab, 0);
	}
	else if ((size % 3 == 1 || size == 3) && add_one == 1 && size != 4)
	{
		array[0] = parse(1, tab);
		array[1] = create_string_recur(nb, tab, 0);
		n = nb;
	}
	else
	{
		return (special_cases_2(nb, size, tab, add_one));
	}
	return (ft_strjoin(2, array, " "));
}

char	*gen_case(unsigned int nb, char **tab, int size, int add_one)
{
	int		n;
	char	**array;

	array = malloc(2 * sizeof(*array));
	if (size % 3 == 2)
	{
		n = nb / power(10, size - 2);
		nb = nb - (n - 1) * power(10, size - 2);
	}
	else
	{
		n = nb / power(10, size - 3);
		nb = nb - (n - 1) * power(10, size - 3);
	}
	array = malloc(3 * sizeof(*tab));
	array[0] = create_string_recur(n, tab, 1);
	array[1] = create_string_recur(nb, tab, 0);
	return (ft_strjoin(2, array, " "));
}

char	*create_string_recur(unsigned int nb, char **tab, int add_one)
{
	int		i;
	int		size;
	char	**array;

	i = first_digit(nb);
	size = number_digits(nb);
	if (nb == 0)
		return ("\0");
	else if (is_in_database(nb))
		return (from_database(nb, tab, add_one));
	else if (size < 4 || size % 3 == 1)
		return (special_cases(nb, i, tab, add_one));
	else
		return (gen_case(nb, tab, size, add_one));
}

char	*create_string(unsigned int nb, char *file)
{
	char	**tab;

	if (nb == 0)
		return (0);
	tab = file_to_array(file);
	if (!tab)
		return ("Dict Error\n");
	return (remove_end_space(create_string_recur(nb, tab, 1)));
}
