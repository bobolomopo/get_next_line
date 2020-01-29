/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:36:33 by jandre            #+#    #+#             */
/*   Updated: 2020/01/29 17:39:39 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*result;
	char	test;

	i = 0;
	test = (char)c;
	result = (char *)s;
	while (s[i])
	{
		if (s[i] == test)
			return (result + i);
		i++;
	}
	if (s[i] == c)
		return (result + i);
	return (NULL);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*result;
	int		i;
	int		size;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return ("");
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(result = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		result[i] = s2[j];
		j++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	if (ft_strlen((const char *)dst) < ft_strlen(src) || !dst || !src)
		return (NULL);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
