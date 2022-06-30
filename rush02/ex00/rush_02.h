/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:57:50 by nseniak           #+#    #+#             */
/*   Updated: 2022/06/30 10:31:35 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_02_H
# define RUSH_02_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>

char			*parse(unsigned int nb, char **tab);

int				ft_strlen(char *str);

char			*ft_strcat_copy(char *str1, char *str2);

int				is_in_database(unsigned int nb);

int				first_digit(unsigned int nb);

int				number_digits(unsigned int nb);

unsigned int	power(unsigned int nb, int n);

char			*from_database(unsigned int nb, char **tab, int add_one);

char			*special_cases(unsigned int nb, int i, char **tab, int add_one);

char			*create_string_recur(unsigned int nb, char **tab, int add_one);

char			*create_string(unsigned int nb, char *file);

int				ft_atoi(char *str);

char			*ft_strcpy(char *dest, char *src);

int				is_sep(char *str, char *charset);

int				word_length(char *str, char *charset);

int				nb_words(char *str, char *charset);

char			**ft_split(char *str, char *charset);

char			*add_space(char *str);

char			*remove_end_space(char *str);

char			*ft_strjoin(int size, char **strs, char *sep);

char			**file_to_array(char *file);

void			ft_putstr(char *str);

long	        ft_atoi_check(char *str);

#endif
