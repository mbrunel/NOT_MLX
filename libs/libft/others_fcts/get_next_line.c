/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:50:13 by mbrunel           #+#    #+#             */
/*   Updated: 2019/12/14 16:57:25 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*setbuff(void)
{
	char *new;

	if (!(new = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	*new = '\0';
	return (new);
}

int					clean(char **buf, int rt)
{
	if (*buf)
		free(*buf);
	*buf = NULL;
	return (rt);
}

int					check(const char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char				*ft_strjoi(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (!(new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
	{
		free(s1);
		return (NULL);
	}
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	free(s1);
	return (new);
}

int					get_next_line(int fd, char **line)
{
	static char		*buf;
	int				st;

	if (!line)
		return (-1);
	*line = malloc(sizeof(char));
	**line = '\0';
	if (!(buf))
		if (!(buf = setbuff()))
			return (-1);
	while ((st = check(buf)) == -1)
	{
		if (!(*line = ft_strjoi(*line, buf)))
			return (clean(&buf, -1));
		if ((st = read(fd, buf, BUFFER_SIZE)) < 1)
			return (clean(&buf, st));
		buf[st] = '\0';
	}
	buf[st] = '\0';
	if (!(*line = ft_strjoi(*line, buf)))
		return (clean(&buf, -1));
	st = ft_strlen(buf);
	ft_memmove(buf, buf + st + 1, ft_strlen(buf + st + 1) + 1);
	return (1);
}
