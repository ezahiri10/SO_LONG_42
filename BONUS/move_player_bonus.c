/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:08:18 by ezahiri           #+#    #+#             */
/*   Updated: 2024/05/06 11:48:46 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_string(t_map *so)
{
	char	*s;

	s = ft_itoa(so->move);
	if (!s)
	{
		memfree(so->map);
		mlx_destroy_window(so->mlx, so->win);
		exit(1);
	}
	xpm_put(so, BLACK, 0, 0);
	mlx_string_put(so->mlx, so->win, 60, 20, 0xFFFFFFFF, s);
	free(s);
}

int	check_move(t_map *so, int x, int y)
{
	if (so->map[so->y + y][so->x + x] == 'E'
		|| so->map[so->y + y][so->x + x] == '1')
		return (0);
	else if (so->map[so->y + y][so->x + x] == 'N')
	{
		ft_printf("YOU LOSE\n");
		clear_mlx(so);
	}
	else if (so->map[so->y + y][so->x + x] == 'C' )
	{
		so->map[so->y + y][so->x + x] = 'P';
		so->map[so->y][so->x] = '0';
		so->nc--;
	}
	else if (so->map[so->y + y][so->x + x] == '0' )
	{
		so->map[so->y + y][so->x + x] = 'P';
		so->map[so->y][so->x] = '0';
	}
	return (1);
}

void	move_player(t_map *so, int x, int y)
{
	if (so->map[so->y + y][so->x + x] == 'E' && so->nc == 0)
	{
		so->move += 1;
		put_string(so);
		mlx_do_sync(so->mlx);
		ft_printf("<<<<-YOU WIN->>>\n");
		clear_mlx(so);
	}
	if (check_move(so, x, y))
	{
		so->move++;
		put_string(so);
		xpm_put(so, SPACE, so->y, so->x);
		so->x += x;
		so->y += y;
		if (x == -1)
			xpm_put(so, PLAYER_LEFT, so->y, so->x);
		else
			xpm_put(so, PLAYER, so->y, so->x);
	}
}
