/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 12:16:51 by hnam              #+#    #+#             */
/*   Updated: 2019/03/01 12:16:52 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		next_line_idx(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

void	ft_concat(char **str, char *buf, int r)
{
	char *temp;

	buf[r] = '\0';
	temp = ft_strjoin(*str, buf);
	ft_strdel(str);
	*str = temp;
}

void	first_setting(char **str)
{
	if (!*str)
		*str = ft_strnew(0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[MAX_SIZE];
	char		buf[BUFF_SIZE + 1];
	int			r;
	int			i;

	if (!line || fd < 0)
		return (-1);
	first_setting(&str[fd]);
	while ((r = read(fd, buf, BUFF_SIZE)) > 0 || *str[fd])
	{
		ft_concat(&str[fd], buf, r);
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
