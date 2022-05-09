/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictio.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseniak <nseniak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:17:41 by mfeldman          #+#    #+#             */
/*   Updated: 2022/02/20 19:47:00 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "rush_02.h"

#define BUF_SIZE 4096

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

char	*parse(unsigned int nb, char **tab)
{
	char	*buf3;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while ((unsigned int)ft_atoi(tab[i]) != nb)
		i++;
	while (tab[i][j] != ':')
	{	
		j++;
		j++;
	}
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
