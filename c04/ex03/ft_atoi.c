/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:33:10 by mfeldman          #+#    #+#             */
/*   Updated: 2022/02/21 23:06:21 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	a;
	int	b;
	int	cont;

	a = 0;
	b = 0;
	cont = 0;
	while (str[a] == ' ' || (str[a] <= 13 && str[a] >= 9))
		a++;
	while (str[a] == '-' || str[a] == '+')
	{	
		if (str[a] == '-')
			cont++;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		b = b * 10 + str[a] - '0';
		a++;
	}
	if (cont % 2 == 0)
		return (b);
	else
		return (b * -1);
}

#include <stdio.h>

int	ft_atoi(char *str);

int	main(void)
{
	printf("42:%d\n", ft_atoi("  \n  42t4457"));
	printf("-42:%d\n", ft_atoi(" --+-42sfs:f545"));
	printf("0:%d\n", ft_atoi("\0 1337"));
	printf("0:%d\n", ft_atoi("-0"));
	printf("0:%d\n", ft_atoi(" - 1 3 2 5 6 3 2 1 6 7"));
	printf("-1325632167:%d\n", ft_atoi("-1325632167"));
	printf("-100:%d\n", ft_atoi("-100"));
	printf("min:%d\n", ft_atoi("\t---+2147483648"));
	printf("max:%d\n", ft_atoi("\v2147483647"));
}
