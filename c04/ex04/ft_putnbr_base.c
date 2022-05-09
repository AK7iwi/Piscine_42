/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:53:44 by mfeldman          #+#    #+#             */
/*   Updated: 2022/02/21 19:42:06 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		a++;
	}
	return (a);
}

int	ft_check_base1(char *base)
{
	int	a;

	a = 0;
	if (base[a] == '\0')
		return (0);
	while (base[a])
	{
		if (base[a] == '+' || base[a] == '-')
			return (0);
		if (base[a] <= 13 && base[a] >= 9)
			return (0);
		if (ft_strlen(base) <= 1)
			return (0);
		a++;
	}
	return (1);
}

int	ft_check_base2(char *base)
{
	int	b;
	int	c;

	b = 0;
	while (base[b])
	{
		c = b + 1;
		while (base[c])
		{
			if (base[c] == base[b])
				return (0);
			c++;
		}
		b++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long 	nb;
	long long	a;
	int		b;
	int		lbase;

	nb = nbr;
	if (ft_check_base1(base) == 1 && ft_check_base2(base) == 1)
	{	
		lbase = ft_strlen(base);
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -(nb);
		}
		a = 1;
		while ((nb / a) >= lbase)
			a = a * lbase;
		while (a > 0)
		{
			b = (nb / a) % lbase;
			ft_putchar(base[b]);
			a = a / lbase;
		}
	}
}

#include <unistd.h>

int		main(void)
{
	ft_putnbr_base(-2147483648, "0123456789");
}
