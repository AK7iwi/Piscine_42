/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:35:26 by mfeldman          #+#    #+#             */
/*   Updated: 2022/02/21 20:25:42 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	a;

	a = 2;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	while (a <= nb / a)
	{
		if (nb % a == 0)
			return (0);
		a++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}
/*
int	main(void)
{
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d\n",
		ft_find_next_prime(-1) == 2 ? "OK" : "Fail",
		ft_find_next_prime(-3) == 2 ? "OK" : "Fail",
		ft_find_next_prime(0) == 2 ? "OK" : "Fail",
		ft_find_next_prime(1) == 2 ? "OK" : "Fail",
		ft_find_next_prime(2) == 2 ? "OK" : "Fail",
		ft_find_next_prime(3) == 3 ? "OK" : "Fail",
		ft_find_next_prime(4) == 5 ? "OK" : "Fail",
		ft_find_next_prime(5) == 5 ? "OK" : "Fail",
		ft_find_next_prime(6) == 7 ? "OK" : "Fail",
		ft_find_next_prime(7) == 7 ? "OK" : "Fail",
		ft_find_next_prime(10) == 11 ? "OK" : "Fail",
		ft_find_next_prime(11) == 11 ? "OK" : "Fail",
		ft_find_next_prime(13) == 13 ? "OK" : "Fail",
		ft_find_next_prime(19) == 19 ? "OK" : "Fail",
		ft_find_next_prime(2147483620));
	printf("yo %d\n", ft_find_next_prime(4));
}
*/
