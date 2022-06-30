/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_fun3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseniak <nseniak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:40:38 by nseniak           #+#    #+#             */
/*   Updated: 2022/02/20 19:44:10 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

char	*add_space(char *str)
{
	int	n;

	n = ft_strlen(str);
	str[n] = ' ';
	str[n + 1] = '\0';
	return (str);
}

char	*remove_end_space(char *str)
{
	int	n;

	n = ft_strlen(str);
	if (str[n - 1] == ' ')
		str[n - 1] = '\0';
	return (str);
}
