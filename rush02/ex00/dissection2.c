/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dissection2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseniak <nseniak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:24:35 by nseniak           #+#    #+#             */
/*   Updated: 2022/02/20 19:38:04 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

char	*from_database(unsigned int nb, char **tab, int add_one)
{
	char	**array;

	if ((nb == 100 || nb % 3 == 1) && add_one == 1 && nb >= 100)
	{
		array = malloc(2 * sizeof(*array));
		array[0] = parse(1, tab);
		array[1] = parse(nb, tab);
		return (ft_strjoin(2, array, " "));
	}
	return (parse(nb, tab));
}
