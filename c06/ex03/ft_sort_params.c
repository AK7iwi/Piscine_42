/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 04:29:35 by mfeldman          #+#    #+#             */
/*   Updated: 2022/02/19 23:30:33 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	char	*c;

	b = argc;
	a = 1;
	while (++a <= argc)
	{
		b = 1;
		while (b <= argc - 1)
		{
			if (ft_strcmp(argv[b], argv[b - 1]) < 0)
			{
				c = argv[b];
				argv[b] = argv[b - 1];
				argv[b - 1] = c;
			}
			b++;
		}
	}
	a = 0;
	while (++a < argc)
		ft_putstr(argv[a]);
}
