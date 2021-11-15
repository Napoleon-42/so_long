/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:38:45 by lnelson           #+#    #+#             */
/*   Updated: 2021/10/18 14:05:46 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player_to_window(t_data *data, int x, int y)
{
	mlx_put_image_to_window((data->mlx), (data->win),
		(data->texture).floor, x, y);
	if ((data->player).on_exit_key == 1)
		mlx_put_image_to_window((data->mlx), (data->win),
			(data->texture).exit, x, y);
	if ((data->player).orient == DOWN)
		mlx_put_image_to_window((data->mlx), (data->win),
			(data->texture).down, x, y);
	if ((data->player).orient == UP)
		mlx_put_image_to_window((data->mlx),
			(data->win), (data->texture).up, x, y);
	if ((data->player).orient == RIGHT)
		mlx_put_image_to_window((data->mlx),
			(data->win), (data->texture).right, x, y);
	if ((data->player).orient == LEFT)
		mlx_put_image_to_window((data->mlx),
			(data->win), (data->texture).left, x, y);
	return ;
}

void	put_potion(t_data *data, int x, int y)
{
	mlx_put_image_to_window((data->mlx),
		(data->win), (data->texture).floor, x, y);
	mlx_put_image_to_window((data->mlx),
		(data->win), (data->texture).potion, x, y);
	return ;
}

void	put_key(t_data *data, int x, int y)
{
	mlx_put_image_to_window((data->mlx),
		(data->win), (data->texture).floor, x, y);
	mlx_put_image_to_window((data->mlx),
		(data->win), (data->texture).exit, x, y);
	return ;
}

void	render_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < (data->map).height)
	{
		x = -1;
		while (++x < (data->map).lenght)
		{
			if ((data->map).map[y][x] == '1')
				mlx_put_image_to_window((data->mlx),
					(data->win), (data->texture).wall, x * 32, y * 32);
			if ((data->map).map[y][x] == '0')
				mlx_put_image_to_window((data->mlx),
					(data->win), (data->texture).floor, x * 32, y * 32);
			if ((data->map).map[y][x] == 'E')
				put_key(data, x * 32, y * 32);
			if ((data->map).map[y][x] == 'P')
				put_player_to_window(data, x * 32, y * 32);
			if ((data->map).map[y][x] == 'C')
				put_potion(data, x * 32, y * 32);
		}
		y++;
	}
	return ;
}
