/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaverdu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:39:16 by glaverdu          #+#    #+#             */
/*   Updated: 2021/01/25 15:28:29 by glaverdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char			*buf;
	int				ret;
	static char		*str;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char*) * BUFFER_SIZE + 1)))
		return (-1);
	ret = 1;
	while ((check_nl(str) && ret != 0))
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	*line = cpystatic(str);
	str = cpyend(str);
	if (ret == 0)
		return (0);
	return (1);
}
