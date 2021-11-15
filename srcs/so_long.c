/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:42:04 by lnelson           #+#    #+#             */
/*   Updated: 2021/11/13 18:51:54 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_exit(void)
{
	write(1, "Error\n", 6);
	return (-1);
}

int	get_key_num(int keycode, t_data *data)
{
	(void)data;
	write(1, "\n", 1);
	ft_putnbr_fd(keycode, 1);
	write(1, "\n", 1);
	return (1);
}

int	get_target(t_map map)
{
	int	x;
	int	y;
	int	res;

	x = 0;
	res = 0;
	while (x < map.height)
	{
		y = 0;
		while (y < map.lenght)
		{
			if (map.map[x][y] == 'C')
				res++;
			y++;
		}
		x++;
	}
	return (res);
}

int	start_game(int ac, char **av, t_data *data)
{
	if (ac == 1)
		return (error_exit());
	if (check_map_ber(av[1]) == -1)
		return (error_exit());
	if (get_map(av[1], data) == NULL)
		return (error_exit());
	if (check_map((data->map)) == 0)
	{
		free_map((data->map).map);
		return (error_exit());
	}
	(data->mlx) = mlx_init();
	(data->win) = mlx_new_window((data->mlx),
			32 * (data->map).lenght, 32 * (data->map).height, "so_long");
	if (get_images(data) == -1)
		return (error_exit());
	data->target = get_target((data->map));
	data->state = 0;
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		return (error_exit());
	else
		close(fd);
	if (start_game(ac, av, &data) == -1)
		return (-1);
	render_map(&data);
	mlx_key_hook(data.win, keys_hooks, &data);
	mlx_hook(data.win, 17, 1L << 2, exit_game, &data);
	mlx_loop(data.mlx);
	return (0);
}
