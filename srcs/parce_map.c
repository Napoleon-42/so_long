/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:41:26 by lnelson           #+#    #+#             */
/*   Updated: 2021/11/09 17:51:04 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_param(char *file, t_data *data)
{
	char	*temp;
	int		fd;
	int		ret;

	ret = 1;
	fd = open(file, O_RDONLY);
	get_next_line(fd, &temp);
	(data->map).lenght = ft_strlen(temp);
	(data->map).height = 1;
	free(temp);
	while (get_next_line(fd, &temp) != 0)
	{
		(data->map).height += 1;
		if (ft_strlen(temp) != (data->map).lenght
			|| ft_str_is_charset(temp, SL_MAP_CHAR) == 0)
			ret = 0;
		free(temp);
	}
	free(temp);
	close(fd);
	return (ret);
}

char	**get_map_exit(char **res)
{
	char	**temp;

	temp = res;
	if (res)
	{
		while (*temp)
		{
			free(*temp);
			temp++;
		}
		free(res);
	}
	return (NULL);
}

char	**get_map(char *file, t_data *data)
{
	char	**res;
	char	*temp;
	int		fd;
	int		i;

	i = 0;
	if (get_map_param(file, data) == 0)
		return (NULL);
	fd = open(file, O_RDONLY);
	res = malloc(sizeof(char *) * ((data->map).height + 1));
	if (res == NULL)
		return (res);
	res[(data->map).height] = 0;
	while (get_next_line(fd, &temp))
	{
		res[i] = ft_strdup((const char *)temp);
		free(temp);
		if (res[i] == NULL)
			 return (get_map_exit(res));
		res[i++][(data->map).lenght] = 0;
	}
	free(temp);
	(data->map).map = res;
	init_player(data);
	return (res);
}

int	check_items(t_map map)
{
	int	i;
	int	j;
	int	items[3];

	items[0] = 0;
	items[1] = 0;
	items[2] = 0;
	i = 1;
	while (i < map.height)
	{
		j = 0;
		while (j++ < map.lenght)
		{
			if (map.map[i][j] == 'E')
				items[0] += 1;
			if (map.map[i][j] == 'P')
				items[1] += 1;
			if (map.map[i][j] == 'C')
				items[2] += 1;
		}
		i++;
	}
	if (items[0] != 1 || items[1] != 1 || items[2] == 0)
		return (0);
	return (1);
}

int	check_map(t_map map)
{
	int	i;

	if (ft_str_is_charset(map.map[0], "1") == 0
		|| ft_str_is_charset(map.map[map.height - 1], "1") == 0
		|| map.height < 3
		|| map.lenght < 3)
		   return (0);
	i = 1;
	while (i < map.height)
	{
		if (map.map[i][0] != '1' || map.map[i][map.lenght - 1] != '1')
			return (0);
		i++;
	}
	if (check_items(map) == 0)
		return (0);
	return (1);
}
