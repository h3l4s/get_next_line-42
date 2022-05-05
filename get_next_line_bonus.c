/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaverdu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:39:16 by glaverdu          #+#    #+#             */
/*   Updated: 2021/01/25 15:28:42 by glaverdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_next_line(int fd, char **line)
{
	char			*buf;
	int				ret;
	static char		*str[256];

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char*) * BUFFER_SIZE + 1)))
		return (-1);
	ret = 1;
	while ((check_nl(str[fd]) && ret != 0))
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[ret] = '\0';
		str[fd] = ft_strjoin(str[fd], buf);
	}
	free(buf);
	*line = cpystatic(str[fd]);
	str[fd] = cpyend(str[fd]);
	if (ret == 0)
		return (0);
	return (1);
}
