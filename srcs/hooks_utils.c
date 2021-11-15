/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:06:32 by lnelson           #+#    #+#             */
/*   Updated: 2021/10/22 16:31:10 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_p_moves(t_player player)
{
	if (player.p_moves != 0)
	{
		ft_putstr_fd("Player moves: ", 1);
		ft_putnbr_fd(player.p_moves, 1);
		write(1, "\n", 1);
	}
	return ;
}

void	collect(t_data *data)
{
	(data->player).collected += 1;
	if ((data->player).collected == data->target)
		data->state = 1;
}

void	check_exit(t_data *data)
{
	if ((data->player).on_exit_key == 1)
	{
		(data->map).map[(data->player).pos[0]][(data->player).pos[1]] = 'E';
		(data->player).on_exit_key = 0;
	}
	else
		(data->map).map[(data->player).pos[0]][(data->player).pos[1]] = '0';
	return ;
}
