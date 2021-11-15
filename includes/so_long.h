/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:42:31 by lnelson           #+#    #+#             */
/*   Updated: 2021/11/13 18:39:37 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "keycodes_linux.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# define XMP_WALL "./textures/wall.xpm"
# define XMP_PLAYER "./textures/player.xpm"
# define XMP_P_UP "./textures/player_up.xpm"
# define XMP_P_RIGHT "./textures/player_righ.xpm"
# define XMP_P_LEFT "./textures/player_left.xpm"
# define XMP_FLOOR "./textures/floor.xpm"
# define XMP_POTION "./textures/potion_red.xpm"
# define XMP_KEY "./textures/key.xpm"
# define SL_MAP_CHAR "01CEP"
# define DOWN 'd'
# define UP 'u'
# define LEFT 'l'
# define RIGHT 'r'

typedef struct s_map
{
	char	**map;
	int		lenght;
	int		height;
}				t_map;

typedef struct s_user
{
	int		pos[2];
	char	orient;
	int		collected;
	char	on_exit_key;
	int		p_moves;
}				t_player;

typedef struct s_image
{
	void	*wall;
	void	*potion;
	void	*exit;
	void	*down;
	void	*up;
	void	*right;
	void	*left;
	void	*floor;
}				t_textures;

typedef struct s_data
{
	t_map		map;
	t_player	player;
	t_textures	texture;
	void		*mlx;
	void		*win;
	int			target;
	char		state;
}				t_data;

/*   -------SO-LONG-------   */
/*   PARCE_MAP.C   */
int		get_map_param(char *file, t_data *data);
char	**get_map(char *file, t_data *data);
char	**get_map_exit(char **res);
int		check_items(t_map map);
int		check_map(t_map map);

/*   INIT_GAME.C   */
int		get_images(t_data *data);
void	init_player(t_data *data);
int		check_map_ber(char *filename);

/*   PUT_TEXTURES.C   */
void	put_player_to_window(t_data *data, int x, int y);
void	put_potion(t_data *data, int x, int y);
void	put_key(t_data *data, int x, int y);
void	render_map(t_data *data);

/*   HOOKS.C   */
void	mv_down(t_data *data);
void	mv_up(t_data *data);
void	mv_left(t_data *data);
void	mv_right(t_data *data);
int		keys_hooks(int keycode, t_data *data);

/*   HOOKS_utils.C   */
void	collect(t_data *data);
void	check_exit(t_data *data);
void	print_p_moves(t_player player);

/*   EXIT_GAME.C   */
void	destroy_textures(t_data *data);
int		free_map(char **map);
int		exit_game(t_data *data);

#endif
