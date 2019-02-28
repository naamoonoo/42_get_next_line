#include "get_next_line.h"

static int	next_line_idx(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*str[MAX_SIZE];
	char		buf[BUFF_SIZE + 1];
	char		*temp;
	int			r;
	int			i;

	if (fd < 0) 
		return (-1);
	if (!str[fd]) 
		str[fd] = ft_strnew(0);
	while ((r = read(fd, buf, BUFF_SIZE)) > 0 || *str[fd])
	{
		buf[r] = '\0';
		temp = ft_strjoin(str[fd], buf);
		ft_strdel(&str[fd]);
		str[fd] = temp;
		if ((i = next_line_idx(str[fd])) >= 0)
		{
			*line = ft_strsub(str[fd], 0, i);
			ft_memmove(str[fd], &str[fd][i + 1], ft_strlen(str[fd]) - i);
			return (1);
		}
		else if (r != BUFF_SIZE)
		{
			*line = ft_strdup(str[fd]);
			ft_strdel(&str[fd]);
			return (1);
		}
	}
	return (r < 0 ? -1 : 0);
}
