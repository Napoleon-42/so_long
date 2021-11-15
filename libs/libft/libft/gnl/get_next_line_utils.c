/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:56:16 by lnelson           #+#    #+#             */
/*   Updated: 2021/10/06 19:51:40 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_gnlstrlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_gnlstrdup(const char *s)
{
	char	*tmp;
	int		i;
	int		u;

	i = 0;
	u = (int)ft_gnlstrlen(s);
	tmp = malloc(sizeof(char) * u + 1);
	if (tmp == NULL)
		return (NULL);
	while (s[i])
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_gnlstrjoin(char **line, char *buff)
{
	char	*tmp;
	int		i;
	int		u;

	i = ft_gnlstrlen(buff);
	tmp = malloc(i + ft_gnlstrlen(*line) + 1);
	i = 0;
	u = 0;
	while ((*line)[u])
	{
		tmp[i] = (*line)[u];
		i++;
		u++;
	}
	u = 0;
	while (buff[u])
	{
		tmp[i] = buff[u];
		i++;
		u++;
	}
	free((char *)*line);
	tmp[i] = '\0';
	return (tmp);
}
