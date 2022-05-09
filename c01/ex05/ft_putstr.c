/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 05:51:56 by mfeldman          #+#    #+#             */
/*   Updated: 2022/02/08 12:50:23 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
/*
#include <stdio.h>

int             main(void)
{
        char str[] = "0123456789";
        char str1[] = "test";
	char str2[] = "ejhfie5545dd5d5";

        printf("0123456789:\n");
        ft_putstr(str);
        printf("\n\ntest:\n");
        ft_putstr(str1);
	ft_putstr(str2);
}
*/
