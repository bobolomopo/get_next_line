/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:12:10 by jandre            #+#    #+#             */
/*   Updated: 2020/01/21 16:37:36 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strnew(int size)
{
	char	*result;
	int		i;

	if (!(result = (char *)malloc(size + 1)))
		return (NULL);
	i = -1;
	while (++i <= size)
		result[i] = '\0';
	return (result);
}

char			*ft_strcpy_from_c(char *str, char *str2, char c)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	i++;
	if (!(result = ft_strnew(ft_strlen(str) - i)))
		return (NULL);
	j = 0;
	while (str[j + i])
	{
		result[j] = str[j + i];
		j++;
	}
	free(str2);
	return (result);
}

char			*ft_strjoin_c(char *s1, char *s2, char c)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	while (s2[i] && s2[i] != c)
		i++;
	if (!(result = (char *)malloc((ft_strlen(s1) + i + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	j = -1;
	while (s2[++j] && s2[j] != c)
		result[i + j] = s2[j];
	result[i + j] = '\0';
	free(s1);
	return (result);
}

int				check_char(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}
