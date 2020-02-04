/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:33:12 by jandre            #+#    #+#             */
/*   Updated: 2020/02/04 16:37:41 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>

int		get_next_line(int fd, char **line);
int		ft_charpos(char *str, char c);
char	*ft_strnew(int size);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strchr(char const *s, int c);
int		ft_strlen(const char *str);
int		ft_initialize(int fd, char **line, char **rest);
int		ft_copy(char **rest, int fd);

#endif
