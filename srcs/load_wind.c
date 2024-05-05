/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_wind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:40:00 by ezahiri           #+#    #+#             */
/*   Updated: 2024/05/05 14:38:30 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_put(char c, int y, int x, t_map *so)
{
	char	*s;

	if (c == '1')
		s = WALL;
	else if (c == '0')
		s = SPACE;
	else if (c == 'E')
		s = EXIT;
	else if (c == 'C')
		s = COLLECTIBLE;
	else
		s = PLAYER;
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

void	move_player(t_map *so, int x, int y)
{
	if (so->map[so->y + y][so->x + x] == '1')
		return ;
	else if (so->map[so->y + y][so->x + x] == 'E' && so->nc == 0)
	{
		ft_printf("move->%d\n<<<<-YOU WIN->>>\n", ++so->move);
		clear_mlx(so);
	}
	else if (so->map[so->y + y][so->x + x] == 'E')
		return ;
	else if (so->map[so->y + y][so->x + x] == 'C' )
	{
		so->map[so->y + y][so->x + x] = '0';
		so->nc--;
	}
	so->map[so->y][so->x] = '0';
	so->map[so->y + y][so->x + x] = 'P';
	ft_printf("move->%d\n", ++so->move);
	xpm_put(so, SPACE, so->y, so->x);
	so->x += x;
	so->y += y;
	if (x == -1)
		xpm_put(so, PLAYER_LEFT, so->y, so->x);
	else
		xpm_put(so, PLAYER, so->y, so->x);
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

void	load_wind(t_map *so)
{
	so->mlx = mlx_init();
	if (!so->mlx)
		exit(memfree(so->map));
	so->win = mlx_new_window(so->mlx, 50 * so->lx, 50 * so->ly, "wind00");
	if (!so->win)
		exit(memfree(so->map));
	so->move = 0;
	render_map(so);
	mlx_hook(so->win, 02, 0, ft_key, so);
	mlx_loop(so->mlx);
}
