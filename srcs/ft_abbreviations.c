/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abbreviations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:03:14 by ezahiri           #+#    #+#             */
/*   Updated: 2024/04/08 00:11:29 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	xpm_put(t_map *so, char *s, int y, int x)
{
	int	a;

	so->img = mlx_xpm_file_to_image(so->mlx, s, &a, &a);
	if (!so->img)
		clear_mlx(so);
	mlx_put_image_to_window(so->mlx, so->win, so->img, x * 50, y * 50);
}
