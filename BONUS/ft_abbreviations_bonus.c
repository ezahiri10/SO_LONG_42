/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abbreviations_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:25:30 by ezahiri           #+#    #+#             */
/*   Updated: 2024/04/07 23:27:43 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	xpm_put(t_map *so, char *s, int y, int x)
{
	int	a;

	so->img = mlx_xpm_file_to_image(so->mlx, s, &a, &a);
	if (!so->img)
		clear_mlx(so);
	mlx_put_image_to_window(so->mlx, so->win, so->img, x * 50, y * 50);
	mlx_destroy_image(so->mlx, so->img);
}
