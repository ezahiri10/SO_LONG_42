/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:31:52 by ezahiri           #+#    #+#             */
/*   Updated: 2024/04/08 00:10:42 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
