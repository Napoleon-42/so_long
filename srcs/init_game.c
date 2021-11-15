/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:53:07 by lnelson           #+#    #+#             */
/*   Updated: 2021/11/15 15:14:32 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_images(t_data *data)
{
	int	d;

	d = 32;
	(data->texture).wall = mlx_xpm_file_to_image((data->mlx), XMP_WALL, &d, &d);
	(data->texture).down = mlx_xpm_file_to_image((data->mlx),
			XMP_PLAYER, &d, &d);
	(data->texture).up = mlx_xpm_file_to_image((data->mlx), XMP_P_UP, &d, &d);
	(data->texture).right = mlx_xpm_file_to_image((data->mlx),
			XMP_P_RIGHT, &d, &d);
	(data->texture).left = mlx_xpm_file_to_image((data->mlx),
			XMP_P_LEFT, &d, &d);
	(data->texture).floor = mlx_xpm_file_to_image((data->mlx),
			XMP_FLOOR, &d, &d);
	(data->texture).potion = mlx_xpm_file_to_image((data->mlx),
			XMP_POTION, &d, &d);
	(data->texture).exit = mlx_xpm_file_to_image((data->mlx), XMP_KEY, &d, &d);
	return (0);
}

void	init_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < (data->map).height)
	{
		j = 0;
		while (j < (data->map).lenght)
		{
			if ((data->map).map[i][j] == 'P')
			{
				((data->player).pos)[0] = i;
				((data->player).pos)[1] = j;
			}
			j++;
		}
		i++;
	}
	(data->player).orient = DOWN;
	(data->player).on_exit_key = 0;
	(data->player).collected = 0;
	(data->player).p_moves = 0;
	return ;
}

int	check_map_ber(char *filename)
{
	int	size;

	size = 0;
	while (filename[size])
		size++;
	size--;
	if (filename[size] != 'r' || filename[size - 1] != 'e'
		|| filename[size - 2] != 'b' || filename[size - 3] != '.')
		return (-1);
	return (0);
}
