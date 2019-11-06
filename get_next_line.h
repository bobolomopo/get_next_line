#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int     get_next_line(int fd, char **line);
char    *ft_strjoin(const char *s1, const char *s2);
int     ft_readline(int fd, char *str);
size_t  ft_strlen(const char *s1);
char    *ft_strnew(int size);
