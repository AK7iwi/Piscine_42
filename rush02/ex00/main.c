/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseniak <nseniak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:26:19 by climousi          #+#    #+#             */
/*   Updated: 2022/02/20 22:35:35 by climousi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"
#include <stdio.h>

long	ft_atoi_check(char *str);

int	main(int argc, char **argv)
{
	long	nb;

	if (argc == 2)
	{	
		nb = ft_atoi_check(argv[1]);
		if (nb >= 0)
			ft_putstr(create_string((unsigned int)nb, "numbers.dict"));
		else
			write(1, "Error", 6);
	}
	else if (argc == 3)
	{
		nb = ft_atoi_check(argv[2]);
		if (nb >= 0)
			ft_putstr(create_string((unsigned int)nb, argv[1]));
		else
			write(1, "Error", 6);
	}
	else
		write(1, "Error", 6);
	write(1, "\n", 1);
}
