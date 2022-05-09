/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseniak <nseniak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:26:19 by climousi          #+#    #+#             */
/*   Updated: 2022/02/20 19:42:31 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush_02.h"

long	ft_atoi_check(char *str);

int	main(int argc, char **argv)
{
	long	nb;

	if (argc == 2)
	{	
		nb = ft_atoi_check(argv[1]);
		if (nb >= 0)
			create_string((unsigned int)nb, "numbers.dict");
		else
			write(1, "Error\n", 6);
	}
	else if (argc == 3)
	{
		nb = ft_atoi_check(argv[2]);
		if (nb >= 0)
			create_string((unsigned int)nb, argv[2]);
		else
			write(1, "Error\n", 6);
	}
	else
	{
		write(1, "Error\n", 6);
	}
}
