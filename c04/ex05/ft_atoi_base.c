/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:12:52 by mfeldman          #+#    #+#             */
/*   Updated: 2022/02/22 05:54:50 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

int	indice(char *str, char *base)
{
	int a;

	a = 0;
	while (base[a])
	{
		if (base[a] = str)
		       return (a);	
	}
	return (-1);
}


int atoi_base( chahr *str, char *base)
{

}
int	main(void)
{
	printf("42:%d\n", ft_atoi_base("2a", "0123456789abcdef"));
	printf("-42:%d\n", ft_atoi_base("   --------+-2a", "0123456789abcdef"));
	printf("42:%d\n", ft_atoi_base("   -+-2a", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+- 2a", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+-z", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", ""));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "0"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "+-0"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "\t01"));
}
