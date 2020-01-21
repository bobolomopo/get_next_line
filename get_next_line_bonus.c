/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:44:56 by jandre            #+#    #+#             */
/*   Updated: 2020/01/21 17:00:53 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*temp[OPEN_MAX];
	int			verif;

	if (fd < 0 || fd >= OPEN_MAX || !line || (!(*line = ft_strnew(0))))
		return (-1);
	if (temp[fd])
	{
		if (!(*line = ft_strjoin_c(*line, temp[fd], '\n')))
			return (-1);
		if (check_char(temp[fd], '\n'))
			return ((temp[fd] = ft_strcpy_from_c(temp[fd],
							temp[fd], '\n')) ? 1 : -1);
	}
	while ((verif = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[verif] = '\0';
		if (!(*line = ft_strjoin_c(*line, buffer, '\n')))
			return (-1);
		if (check_char(buffer, '\n'))
			return ((temp[fd] = ft_strcpy_from_c(buffer,
							temp[fd], '\n')) ? 1 : -1);
	}
	free(*line);
	return (verif);
}
