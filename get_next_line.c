/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:58:47 by jandre            #+#    #+#             */
/*   Updated: 2020/01/29 18:06:44 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int		ft_charpos(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int				get_next_line(int fd, char **line)
{
	static char	*rest[FOPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	char		*ptr;
	int			verif;

	if (fd > FOPEN_MAX || !line)
		return (-1);
	if (rest[fd] == NULL)
	{
		if (!(rest[fd] = ft_strnew(0)))
			return (-1);
	}
	while (!(ft_strchr(rest[fd], '\n')) &&
			(verif = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[verif] = '\0';
		ptr = rest[fd];
		if (!(rest[fd] = ft_strjoin(ptr, buffer)))
			return (-1);
		free(ptr);
	}
	if (!(*line = ft_substr(rest[fd], 0, ft_charpos(rest[fd], '\n'))))
		return (-1);
	if (ft_strchr(rest[fd], '\n'))
	{
		ft_strcpy(rest[fd], ft_strchr(rest[fd], '\n') + 1);
		return (1);
	}
	if (ft_strlen(rest[fd]) > 0)
	{
		rest[fd] = ft_strchr(rest[fd], '\0');
		return (1);
	}
	return (0);
}

