/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:48:13 by jandre            #+#    #+#             */
/*   Updated: 2020/01/21 16:48:55 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>

int				get_next_line(int fd, char **line);
int				ft_strlen(char *str);
char			*ft_strnew(int size);
char			*ft_strcpy_from_c_to_c(char *str, char *str2, char c);
char			*ft_strjoin_c(char *s1, char *s2, char c);
int				check_char(char *str, char c);

#endif
