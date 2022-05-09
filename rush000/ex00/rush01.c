/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:42:29 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/06 18:56:10 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char d);

void	ft_lignes(char a, char b, char c, int x)
{
	ft_putchar(a);
	while (x-- > 2)
	{
		ft_putchar(b);
	}
	if (x == 1)
		ft_putchar(c);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (x < 0 && y < 0)
		return ;
	if (x != 0 && y != 0)
	{
		ft_lignes('/', '*', '\\', x);
		while (y-- > 2)
		{	
			ft_lignes('*', ' ', '*', x);
		}
		if (y == 1)
			ft_lignes('\\', '*', '/', x);
	}
}
