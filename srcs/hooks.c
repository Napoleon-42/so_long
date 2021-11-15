/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:36:10 by lnelson           #+#    #+#             */
/*   Updated: 2021/11/09 17:55:08 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mv_down(t_data *data)
{
	(data->player).orient = DOWN;
	if ((data->map).map[(data->player).pos[0] + 1][(data->player).pos[1]]
		!= '1')
	{
		if ((data->map).map[(data->player).pos[0] + 1][(data->player).pos[1]]
			== 'C')
			collect(data);
		check_exit(data);
		(data->player).pos[0] += 1;
		if ((data->map).map[(data->player).pos[0]][(data->player).pos[1]]
			== 'E')
			(data->player).on_exit_key = 1;
		(data->map).map[(data->player).pos[0]][(data->player).pos[1]] = 'P';
		(data->player).p_moves += 1;
		print_p_moves(data->player);
	}
	render_map(data);
}

void	mv_up(t_data *data)
{
	(data->player).orient = UP;
	if ((data->map).map[(data->player).pos[0] - 1][(data->player).pos[1]]
		!= '1')
	{
		if ((data->map).map[(data->player).pos[0] - 1][(data->player).pos[1]]
			== 'C')
			collect(data);
		check_exit(data);
		(data->player).pos[0] -= 1;
		if ((data->map).map[(data->player).pos[0]][(data->player).pos[1]]
			== 'E')
			(data->player).on_exit_key = 1;
		(data->map).map[(data->player).pos[0]][(data->player).pos[1]] = 'P';
		(data->player).p_moves += 1;
		print_p_moves(data->player);
	}
	render_map(data);
}

void	mv_left(t_data *data)
{
	(data->player).orient = LEFT;
	if ((data->map).map[(data->player).pos[0]][(data->player).pos[1] - 1]
		!= '1')
	{
		if ((data->map).map[(data->player).pos[0]][(data->player).pos[1] - 1]
			== 'C')
			collect(data);
		check_exit(data);
		(data->player).pos[1] -= 1;
		if ((data->map).map[(data->player).pos[0]][(data->player).pos[1]]
			== 'E')
			(data->player).on_exit_key = 1;
		(data->map).map[(data->player).pos[0]][(data->player).pos[1]] = 'P';
		(data->player).p_moves += 1;
		print_p_moves(data->player);
	}
	render_map(data);
}

void	mv_right(t_data *data)
{
	(data->player).orient = RIGHT;
	if ((data->map).map[(data->player).pos[0]][(data->player).pos[1] + 1]
		!= '1')
	{
		if ((data->map).map[(data->player).pos[0]][(data->player).pos[1] + 1]
			== 'C')
			collect(data);
		check_exit(data);
		(data->player).pos[1] += 1;
		if ((data->map).map[(data->player).pos[0]][(data->player).pos[1]]
			== 'E')
			(data->player).on_exit_key = 1;
		(data->map).map[(data->player).pos[0]][(data->player).pos[1]] = 'P';
		(data->player).p_moves += 1;
		print_p_moves(data->player);
	}
	render_map(data);
}

int	keys_hooks(int keycode, t_data *data)
{
	if (keycode == W)
		mv_up(data);
	if (keycode == A)
		mv_left(data);
	if (keycode == S)
		mv_down(data);
	if (keycode == D)
		mv_right(data);
	if (keycode == ESC)
		exit_game(data);
	if (data->mlx != 0 && data->win != 0 && (data->map).map != 0
		&& data->state == 1 && (data->player).on_exit_key == 1)
		exit_game(data);
	return (1);
}
