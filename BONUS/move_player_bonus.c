/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:08:18 by ezahiri           #+#    #+#             */
/*   Updated: 2024/04/08 00:27:43 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_move(t_map *so, int x, int y)
{
	if (so->map[so->y + y][so->x + x] == 'E' && so->nc == 0)
	{
		ft_printf("move->%d\n<<<<-YOU WIN->>>\n", ++so->move);
		clear_mlx(so);
	}
	else if (so->map[so->y + y][so->x + x] == 'E'
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
	if (check_move(so, x, y))
	{
		ft_printf("move->%d\n", ++so->move);
		xpm_put(so, SPACE, so->y, so->x);
		so->x += x;
		so->y += y;
		if (x == -1)
			xpm_put(so, PLAYER_LEFT, so->y, so->x);
		else
			xpm_put(so, PLAYER, so->y, so->x);
	}
}
