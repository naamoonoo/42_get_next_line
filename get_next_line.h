/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 12:16:57 by hnam              #+#    #+#             */
/*   Updated: 2019/03/01 12:16:58 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# define BUFF_SIZE 32
# define MAX_FD 10000

int		next_line_idx(char *str);
void	ft_concat(char **str, char *buf, int r);
void	first_setting(char **str);
int		get_next_line(const int fd, char **line);

#endif
