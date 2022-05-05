/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaverdu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:39:52 by glaverdu          #+#    #+#             */
/*   Updated: 2021/01/19 12:51:31 by glaverdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (s2)
	{
		if (s1)
			len1 = ft_strlen(s1);
		else
			len1 = 0;
		len2 = ft_strlen(s2);
		if (!(str = malloc(sizeof(char*) * (len1 + len2 + 1))))
			return (NULL);
		i = -1;
		while (s1 && s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i] && s2[i])
			str[len1++] = s2[i];
		str[len1] = '\0';
		free(s1);
		return (str);
	}
	return (NULL);
}

char	*cpystatic(char *src)
{
	int		i;
	char	*destm;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i] != '\n' && src[i])
		i++;
	if (!(destm = malloc(sizeof(char *) * i + 1)))
		return (NULL);
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		destm[i] = src[i];
		i++;
	}
	destm[i] = '\0';
	return (destm);
}

char	*cpyend(char *str)
{
	int		i;
	int		k;
	char	*strm;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	k = i;
	while (str[k])
		k++;
	if (!(strm = malloc(sizeof(char *) * (k - i) + 1)))
		return (NULL);
	k = 0;
	while (str[i])
		strm[k++] = str[i++];
	free(str);
	strm[k] = '\0';
	return (strm);
}

int		check_nl(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}
