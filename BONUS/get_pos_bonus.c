/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:35:02 by ezahiri           #+#    #+#             */
/*   Updated: 2024/04/08 00:32:30 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_pos(t_map *info, char **strs)
{
	int	i;
	int	j;

	i = -1;
	while (strs[++i])
	{
		j = 0;
		while (strs[i][j] && strs[i][j] != 'P')
			j++;
		if (strs[i][j] == 'P')
			break ;
	}
	info->x = j;
	info->y = i;
}
