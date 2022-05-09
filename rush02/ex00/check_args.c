/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseniak <nseniak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:22:30 by climousi          #+#    #+#             */
/*   Updated: 2022/02/20 00:08:57 by nseniak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Check if the input is an integer number
int	is_integer(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// Power function used to calculate the max value of an unsigned int
long	ft_recursive_power(int nb, int power)
{
	if (power == 0)
	{
		return (1);
	}
	return (nb * ft_recursive_power(nb, power - 1));
}

// Convert string->int, returns -1 if the result is not an unsigned int
long	ft_atoi_check(char *str)
{
	long	res;
	int		i;

	res = 0;
	if (!is_integer(str))
		res = -1;
	i = 0;
	while (str[i] != '\0' && res >= 0)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (res >= ft_recursive_power(2, sizeof(unsigned int) * 8))
	{
		res = -1;
	}
	return (res);
}
