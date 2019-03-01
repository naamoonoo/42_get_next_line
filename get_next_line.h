#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# define BUFF_SIZE 32
# define MAX_SIZE 4864

int	next_line_idx(char *str);
void ft_concat(char **str, char *buf, int r);
void first_setting(char **str);
int get_next_line(const int fd, char **line);

#endif
