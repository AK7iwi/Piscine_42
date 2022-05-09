/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 06:19:44 by mfeldman          #+#    #+#             */
/*   Updated: 2022/02/24 19:44:20 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		a++;
	}
	write(1, str, a);
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

void	ft_show_tab(struct s_stock_str *par)
{
	int		i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}
