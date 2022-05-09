/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:19:22 by mfeldman          #+#    #+#             */
/*   Updated: 2022/02/22 21:55:43 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	a;
	unsigned int	b;

	a = 0;
	b = 0;
	while (src[b] != '\0')
		b++;
	while (dest[a] != '\0')
		a++;
	if (size < a)
		b = b + size;
	else
		b = b + a;
	while (src && a < (size - 1) && size != 0)
	{
		dest[a] = *src;
		src++;
		a++;
	}	
	dest[a] = '\0';
	return (b);
}
