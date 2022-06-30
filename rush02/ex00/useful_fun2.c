/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_fun2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseniak <nseniak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:01:37 by nseniak           #+#    #+#             */
/*   Updated: 2022/02/20 20:12:04 by nseniak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int	number_digits(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb)
	{
		nb = nb / 10;
		i ++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int	nb;
	int	s;

	nb = 0;
	s = 1;
	while ((9 <= str[0] && str[0] <= 13) || str[0] == ' ')
		str ++;
	while ((str[0] == '-') || (str[0] == '+'))
	{
		if (str[0] == '-')
			s *= -1;
		str ++;
	}
	while (('0' <= str[0]) && (str[0] <= '9'))
	{
		nb = nb * 10 + str[0] - '0';
		str ++;
	}
	return (nb);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
