#include "get_next_line.h"

char    *ft_strnew(int size)
{
    char    *str;
    int     i;

    if (!(str = (char*)malloc(size + 1)))
        return (NULL);
    i = -1;
    while (str[++i])
        str[i] = '\0';
    str[i] = '\0';
    return (str);
}

size_t  ft_strlen(const char *s1)
{
    size_t  i;

    i = 0;
    while (s1[i])
        i++;
    return (i);
}

char    *ft_strjoin(const char *s1, const char *s2)
{
    int     i;
    char    *str;

    i - ft_strlen(s1) + ft_strlen(s2);
    if (!(str = ft_strnew(i)))
        return (NULL);
    while (s1)
        *str++ = *s1++;
    while (s2)
        *str++ = *s2++;
    return (str);
}

char     *ft_readline(int fd, char *str)
{
    int     verif;
    char    temp[BUFF_SIZE + 1]
    
    if (fd < 0 || !str)
        return (NULL);
    while (verif = read(fd, temp, BUFF_SIZE))
    {
        temp[verif] = '\0';
        str = ft_strjoin(str, temp);
    }
    return (str);
}