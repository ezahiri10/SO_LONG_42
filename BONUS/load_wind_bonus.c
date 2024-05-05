/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_wind_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:42:17 by ezahiri           #+#    #+#             */
/*   Updated: 2024/05/05 20:15:02 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_put(char c, int y, int x, t_map *so)
{
	char	*s;

	if (c == '1')
		s = WALL;
	else if (c == '0')
		s = SPACE;
	else if (c == 'E')
		s = EXIT;
	else if (c == 'N')
		s = ENEMY_F;
	else if (c == 'C')
		s = COIN1;
	else
		s = PLAYER;
	xpm_put(so, BLACK, 0, 0);
	if (so->move == 0)
		put_string(so);
	xpm_put(so, s, y, x);
}

void	render_map(t_map *so)
{
	char	**strs;
	int		x;
	int		y;

	y = -1;
	strs = so->map;
	while (strs[++y])
	{
		x = -1;
		while (strs[y][++x])
			check_put(strs[y][x], y, x, so);
	}
}

int	ft_key(int key, t_map *so)
{
	if (key == 53)
		clear_mlx(so);
	else if (key == 0 || key == 123)
		move_player(so, -1, 0);
	else if (key == 1 || key == 125)
		move_player(so, 0, 1);
	else if (key == 2 || key == 124)
		move_player(so, 1, 0);
	else if (key == 13 || key == 126)
		move_player(so, 0, -1);
	return (0);
}

int	moves(t_map *so)
{
	sprite_coin(so);
	enemy_patrol(so);
	return (0);
}

void	load_wind(t_map *so)
{
	so->mlx = mlx_init();
	if (!so->mlx)
		return ;
	so->win = mlx_new_window(so->mlx, 50 * so->lx, 50 * so->ly, "wind00");
	if (!so->win)
		return ;
	so->move = 0;
	so->nn = ft_count(so->map, 'N');
	render_map(so);
	mlx_hook(so->win, 02, 0, ft_key, so); 
	mlx_hook(so->win, 17, 0, clear_mlx, so);
	mlx_loop_hook(so->mlx, moves, so);
	mlx_loop(so->mlx);
}
