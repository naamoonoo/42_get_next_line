#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# define BUFF_SIZE 32
# define MAX_SIZE 10000

int get_next_line(const int fd, char **line);

#endif
