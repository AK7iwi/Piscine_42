/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:28:13 by mfeldman          #+#    #+#             */
/*   Updated: 2022/02/15 21:28:25 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char d)
{
	write(1, &d, 1);
}

void	ft_putnbr(int nb)
{
	long long	b;

	b = nb;
	if (b < 0)
	{
		ft_putchar('-');
		b *= -1;
	}
	if (b <= 9)
	{
		ft_putchar('0' + b);
	}
	else if (b > 9)
	{
		ft_putnbr(b / 10);
		ft_putchar('0' + b % 10);
	}
}
