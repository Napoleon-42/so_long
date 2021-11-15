/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 07:48:14 by lnelson           #+#    #+#             */
/*   Updated: 2021/09/11 08:13:37 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	reader(char *buff, char *memory, int fd)
{
	int	res;

	if (memory)
	{
		ft_strcpy(buff, memory);
		free(memory);
		return (1);
	}
	res = read(fd, buff, BUFFER_SIZE);
	buff[res] = 0;
	return (res);
}

void	norm(int *i, char *buff)
{
	*i = 0;
	while (buff[*i] != '\n')
		*i = *i + 1;
}

int	get_one_line(int i, int fd, char **line, char *buff)
{
	static char	*memory;
	int			res;

	res = (reader(buff, memory, fd));
	*line = ft_gnlstrdup("");
	while (res > 0)
	{
		if (memory)
			memory = 0;
		if (ft_strrchr(buff, '\n') >= 0)
		{
			norm(&i, buff);
			buff[i] = 0;
			if (!memory)
				memory = ft_gnlstrdup(buff + i + 1);
			*line = ft_gnlstrjoin(line, buff);
			return (1);
		}
		else
			*line = ft_gnlstrjoin(line, buff);
		res = (reader(buff, memory, fd));
	}
	if (*line == NULL)
		*line = ft_gnlstrdup("");
	return (res);
}

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	int			index;
	char		*temp;

	index = 0;
	temp = ft_gnlstrdup("");
	if (!line || BUFFER_SIZE < 1 || read(fd, temp, 0) < 0)
		return (-1);
	free(temp);
	temp = 0;
	return (get_one_line(index, fd, line, buff));
}
