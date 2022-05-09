/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:29:35 by mfeldman          #+#    #+#             */
/*   Updated: 2022/02/13 11:47:23 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	char	*a;

	a = str;
	while (*a)
	{
		if (*a >= 'A' && *a <= 'Z')
		{
			*a += 32;
		}
		a++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	a;

	a = 0;
	ft_strlowcase(str);
	if (str[0] >= 'a' && str[a] <= 'z')
	{
		str[0] -= 32;
	}
	while (str[a])
	{
		if (!(str[a] >= 'a' && str[a] <= 'z'))
		{
			if (!(str[a] >= '0' && str[a] <= '9'))
			{
				if (!(str[a] <= 'Z' && str[a] >= 'A'))
				{
					if (str[a + 1] >= 'a' && str[a + 1] <= 'z')
						str[a + 1] -= 32;
				}
			}
		}
		a++;
	}		
	return (str);
}
