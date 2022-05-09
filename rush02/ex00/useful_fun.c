/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseniak <nseniak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:00:11 by nseniak           #+#    #+#             */
/*   Updated: 2022/02/20 17:10:39 by nseniak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i ++;
	}
	return (i);
}

int	first_digit(unsigned int nb)
{
	while (nb >= 10)
		nb = (nb / 10);
	return (nb);
}

unsigned int	power(unsigned int nb, int n)
{
	if (n == 0)
		return (1);
	return (nb * power(nb, n - 1));
}

int	is_in_database(unsigned int nb)
{
	int	i;

	if (nb <= 20)
		return (1);
	if (1 <= nb / 10 && nb / 10 <= 10 && nb % 10 == 0)
		return (1);
	i = 0;
	while (nb >= 1000)
	{
		i ++;
		if (nb == 1000 && i <= 13)
			return (1);
		nb = nb / 1000;
	}
	return (0);
}
