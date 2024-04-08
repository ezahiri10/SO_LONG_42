/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:44:16 by ezahiri           #+#    #+#             */
/*   Updated: 2024/04/08 02:20:22 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <time.h>
# include "../libft/libft.h"

# define WALL "textures/WALL.xpm"
# define EXIT "textures/EXIT.xpm"
# define PLAYER "textures/PLAYER.xpm"
# define SPACE "textures/SPACE.xpm"
# define PLAYER_LEFT "textures/PLAYER_LEFT.xpm"
# define COLLECTIBLE "textures/COLLECTIBLE.xpm"
# define ENEMY  "textures/ENEMY.xpm"
# define ENEMY_B  "textures/Back.xpm"
# define ENEMY_L  "textures/Left.xpm"
# define ENEMY_F  "textures/Front.xpm"
# define ENEMY_R  "textures/Right.xpm"
# define BLACK "textures/black_image.xpm"
# define COIN1 "textures/coin1.xpm"
# define COIN2 "textures/coin2.xpm"
# define COIN3 "textures/coin3.xpm"
# define COIN4 "textures/coin4.xpm"
# define COIN5 "textures/coin5.xpm"
# define COIN6 "textures/coin6.xpm"
# define COIN7 "textures/coin7.xpm"
# define COIN8 "textures/coin8.xpm"

typedef struct s_enemy
{
	int	x;
	int	y;
	int	to;
}	t_enemy;

typedef struct s_map
{
	char	**map;
	char	**copy;
	void	*mlx;
	void	*win;
	void	*img;
	t_enemy	en[3];
	int		lx;
	int		ly;
	int		x;
	int		y;
	int		nc;
	int		nn;
	int		move;
}	t_map;

char	*parsing(char *name);
int		memfree(char **strs);
int		check_elem(char **strs, char *s);
void	get_pos(t_map *info, char **strs);
int		ft_count(char **strs, char c);
int		check_ff(char **map, int y, int x);
void	load_wind(t_map *so);
int		error_crash(char **strs, char *s, char *err, char mod);
int		clear_mlx(t_map *so);
int		ft_nb_line(char **strs);
void	xpm_put(t_map *so, char *s, int y, int x);
void	enemy_patrol(t_map *so);
void	move_player(t_map *so, int x, int y);
void	sprite_coin(t_map *so);
void	put_string(t_map *so);

#endif