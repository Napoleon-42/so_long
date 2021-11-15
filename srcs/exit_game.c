/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:17:55 by lnelson           #+#    #+#             */
/*   Updated: 2021/10/18 14:21:20 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_textures(t_data *data)
{
	mlx_destroy_image((data->mlx), (data->texture).wall);
	mlx_destroy_image((data->mlx), (data->texture).potion);
	mlx_destroy_image((data->mlx), (data->texture).exit);
	mlx_destroy_image((data->mlx), (data->texture).down);
	mlx_destroy_image((data->mlx), (data->texture).up);
	mlx_destroy_image((data->mlx), (data->texture).right);
	mlx_destroy_image((data->mlx), (data->texture).left);
	mlx_destroy_image((data->mlx), (data->texture).floor);
}

int	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	return (1);
}

int	exit_game(t_data *data)
{
	if ((data->texture).wall != 0)
	{
		destroy_textures(data);
		mlx_destroy_window((data->mlx), (data->win));
		free_map((data->map).map);
		mlx_destroy_display((data->mlx));
		if (data->mlx)
			free((data->mlx));
	}
	exit(0);
	return (1);
}
