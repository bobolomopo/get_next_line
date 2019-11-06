#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
    static char stock[BUFFER_SIZE + 1];

    if (fd < 0 || !line || (verif = ft_readline(line, fd)) < 0)
        return (-1);
    if (verif == 0)
    {
        *line = ft_strnew(0);
        return (0);
    }
    
    return (1);
}
