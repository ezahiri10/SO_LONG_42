/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_coin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 01:30:56 by ezahiri           #+#    #+#             */
/*   Updated: 2024/04/08 01:31:42 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	sprite_coin(t_map *so)
{
	static int	t;
	static int	j = '1';
	static char	str[] = "textures/coin_.xpm";
	int			x;
	int			y;

	if (t++ == 1500)
	{
		y = -1;
		while (so->map[++y])
		{
			x = -1;
			while (so->map[y][++x])
			{
				if (so->map[y][x] == 'C')
				{
					str[13] = j;
					xpm_put (so, str, y, x);
				}
			}
		}
		t = 0;
		if (++j == '9')
			j = '1';
	}
}
