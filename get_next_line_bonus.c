/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poscenes <poscenes@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:02:33 by poscenes          #+#    #+#             */
/*   Updated: 2021/11/02 14:00:05 by poscenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_str(int fd, char *line)
{
	char		*buf;
	int			rd;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rd = -1;
	while (rd && check_endl(buf))
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[rd] = '\0';
		line = ft_strjoin(line, buf);
	}
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str[FD_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = get_str(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = get_line(str[fd]);
	if (!ft_strlen(line))
	{
		free(line);
		if (str[fd])
		{
			free(str[fd]);
			str[fd] = NULL;
		}
		return (NULL);
	}
	str[fd] = get_remain(str[fd]);
	return (line);
}
