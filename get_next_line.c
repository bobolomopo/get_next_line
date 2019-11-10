#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
    static char stock[BUFFER_SIZE + 1];
    int i;

    if (fd < 0 || !line)
        return (-1);
    stock = ft_readline(fd, stock);
    if (!*stock)
    {
        if (!(*line = ft_strnew(0)))
            return (-1);
        return (0);
    }
    i = -1;
    while (stock[++i] && stock[i] != '\n')
    if (!(line = ft_strnew(i)))
        return (-1);
    i = -1;
    while (stock[++i] && stock[i] != '\n')
        stock[i] = *line[i];
    stock += (i + 1);
    return (1);
}
