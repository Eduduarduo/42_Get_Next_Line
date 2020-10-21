/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 20:16:52 by edbarbos          #+#    #+#             */
/*   Updated: 2020/10/20 21:17:22 by edbarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*s_line;
	char		*buffer;
	int			ret;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	ret = 1;
	*line = NULL;
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!(s_line))
		s_line = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (isbreakline(s_line) == -1 && ret >= 1 && ret <= BUFFER_SIZE)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret >= 1 && ret <= BUFFER_SIZE && s_line)
			s_line = ft_strjoin(s_line, buffer);
		ft_bzero(buffer);
	}
	if (ret >= 0 && ret <= BUFFER_SIZE)
		s_line = cleanline(line, s_line);
	free(buffer);
	if (ret >= 1 && ret <= BUFFER_SIZE)
		return (1);
	return (ret == 0 ? 0 : -1);
}

char	*cleanline(char **line, char *s_line)
{
	char	*tmp;
	int		pos;

	pos = isbreakline(s_line);
	if (pos >= 0)
	{
		s_line[pos] = '\0';
		*line = ft_calloc(pos + 1, sizeof(char));
		tmp = ft_calloc(ft_strlen(&s_line[pos + 1]) + 1, sizeof(char));
		ft_strlcpy(*line, s_line, pos + 1);
		ft_strlcpy(tmp, &s_line[pos + 1], ft_strlen(&s_line[pos + 1]) + 1);
		free(s_line);
		s_line = NULL;
		return (tmp);
	}
	*line = (char *)ft_calloc(ft_strlen(s_line) + 1, sizeof(char));
	ft_strlcpy(*line, s_line, ft_strlen(s_line) + 1);
	free(s_line);
	s_line = NULL;
	return (s_line);
}

int		isbreakline(char *string)
{
	int i;

	if (!(string))
		return (-1);
	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
