/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:49:18 by ezahiri           #+#    #+#             */
/*   Updated: 2024/04/07 23:55:02 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	error_crash(char **strs, char *s, char *err, char mod)
{
	if (mod == 0)
	{
		free(s);
		memfree(strs);
	}
	else if (mod == 1)
		free(s);
	ft_printf ("Error\n%s", err);
	exit(1);
}

void	clear_mlx(t_map *so)
{
	memfree(so->map);
	mlx_destroy_window(so->mlx, so->win);
	exit(0);
}
