/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 00:25:50 by ezahiri           #+#    #+#             */
/*   Updated: 2024/04/08 00:25:05 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	postion_enemy(t_map *so)
{
	int		x;
	int		y;
	int		n;
	char	**strs;

	x = 0;
	y = 0;
	n = 0;
	strs = so->map;
	while (strs[y])
	{
		x = 0;
		while (strs[y][x])
		{
			if (strs[y][x] == 'N')
			{
				so->en[n].x = x;
				so->en[n].y = y;
				n++;
			}
			x++;
		}
		y++;
	}
}
void	is_valid(int y, int x, t_map *so, int i);

void	set_map(t_map *so, int b, int a, int i)
{
	int	x;
	int	y;

	x = so->en[i].x;
	y = so->en[i].y;
	if (so->map[y + b][x + a] == 'P')
	{
		ft_printf ("You ARE Loser\n");
		clear_mlx (so);
	}
	so->map[y + b][x + a] = 'N';
	so->map[y][x] = '0';
}

void	is_valid(int y, int x, t_map *so, int i)
{
	static int	m;
	char		**s;

	m = clock();
	s = so->map;
	if ((s[y - 1][x] == '0' || s[y - 1][x] == 'P') && m % 4 == 0)
		(set_map(so, -1, 0, i), so->en[i].to = 1);
	else if ((s[y][x + 1] == '0' || s[y][x + 1] == 'P') && m % 4 == 1)
		(set_map(so, 0, 1, i), so->en[i].to = 2);
	else if ((s[y + 1][x] == '0' || s[y + 1][x] == 'P') && m % 4 == 2)
		(set_map(so, 1, 0, i), so->en[i].to = 3);
	else if ((s[y][x - 1] == '0' || s[y][x - 1] == 'P') && m % 4 == 3)
		(set_map(so, 0, -1, i), so->en[i].to = 4);
}

void	check_flag(t_map *so, int i)
{
	if (so->en[i].to == 1)
	{
		xpm_put(so, SPACE, so->en[i].y, so->en[i].x);
		xpm_put(so, ENEMY_B, so->en[i].y - 1, so->en[i].x);
	}
	else if (so->en[i].to == 2)
	{
		xpm_put(so, SPACE, so->en[i].y, so->en[i].x);
		xpm_put(so, ENEMY_R, so->en[i].y, so->en[i].x + 1);
	}
	else if (so->en[i].to == 3)
	{
		xpm_put(so, SPACE, so->en[i].y, so->en[i].x);
		xpm_put(so, ENEMY_F, so->en[i].y + 1, so->en[i].x);
	}
	else if (so->en[i].to == 4)
	{
		xpm_put(so, SPACE, so->en[i].y, so->en[i].x);
		xpm_put(so, ENEMY_L, so->en[i].y, so->en[i].x - 1);
	}
}

void	enemy_patrol(t_map *so)
{
	static int	t;
	int			i;

	t++;
	i = 0;
	if (t == 4500)
	{
		postion_enemy(so);
		while (i < so->nn)
		{
			so->en[i].to = 0;
			is_valid(so->en[i].y, so->en[i].x, so, i);
			if (so->en[i].to != 0)
				check_flag(so, i);
			i++;
			t = 0;
		}
	}
}
