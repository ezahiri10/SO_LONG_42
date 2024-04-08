/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandle_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:28:09 by ezahiri           #+#    #+#             */
/*   Updated: 2024/04/08 00:01:48 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

int	clear_mlx(t_map *so)
{
	memfree(so->map);
	mlx_destroy_window(so->mlx, so->win);
	exit(0);
	return (0);
}
