/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictio.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseniak <nseniak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:17:41 by mfeldman          #+#    #+#             */
/*   Updated: 2022/02/20 20:14:27 by nseniak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

#define BUF_SIZE 4096

char	**file_to_array(char *file)
{
	char	*buf;
	char	**tab;
	int		fd;
	int		ret;

	buf = malloc((BUF_SIZE + 1) * sizeof(*buf));
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		return (NULL);
	}
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (close(fd) == -1)
	{
		return (NULL);
	}
	tab = ft_split(buf, "\n");
	free(buf);
	return (tab);
}

int	get_line_number(char **tab, unsigned int nb)
{
	int	i;

	i = 0;
	while ((unsigned int)ft_atoi(tab[i]) != nb)
		i++;
	return (i);
}

char	*parse(unsigned int nb, char **tab)
{
	char	*buf3;
	int		i;
	int		j;
	int		k;

	i = get_line_number(tab, nb);
	j = 0;
	while (tab[i][j] != ':')
		j++;
	j ++;
	while (tab[i][j] == ' ')
		j++;
	k = 0;
	while (tab[i][j + k] >= 'a' && tab[i][j + k] <= 'z')
		k++;
	buf3 = malloc((k + 1) * sizeof * buf3);
	k = 0;
	while (tab[i][j + k] >= 'a' && tab[i][j + k] <= 'z')
	{
		buf3[k] = tab[i][j + k];
		k ++;
	}
	buf3[k] = '\0';
	return (buf3);
}
