/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:11:51 by mfeldman          #+#    #+#             */
/*   Updated: 2022/02/21 18:09:05 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	a;

	a = index;
	if (index < 0)
	{	
		return (-1);
	}
	if (index == 0)
	{	
		return (0);
	}
	if (index == 1)
	{
		return (1);
	}
	a = ft_fibonacci(a - 1) + ft_fibonacci(a - 2);
	return (a);
}
/*
int	main(void)
{
	printf("0:%d\n", ft_fibonacci(0));
	printf("1:%d\n", ft_fibonacci(1));
	printf("1:%d\n", ft_fibonacci(2));
	printf("2:%d\n", ft_fibonacci(3));
	printf("55:%d\n", ft_fibonacci(10));
}
*/
