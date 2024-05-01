/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:12:54 by ezahiri           #+#    #+#             */
/*   Updated: 2024/05/01 22:07:47 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_ext(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (len < 4)
		return (1);
	if (ft_strcmp(s + len - 4, ".ber"))
	{
		ft_printf ("error extention\n");
		return (1);
	}
	return (0);
}

int	is_rectangle(char **strs, char *s)
{
	int		i;
	size_t	len;

	i = 1;
	len = ft_strlen (strs[0]);
	while (strs[i])
	{
		if (ft_strlen (strs[i]) != len)
			error_crash(strs, s, "error dimention\n", 0);
		i++;
	}
	return (0);
}

int	is_wall(char **strs, char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (strs[0][i])
	{
		if (strs[0][i] != '1')
			error_crash(strs, s, "error wall\n", 0);
		i++;
	}
	len = ft_nb_line(strs) - 1;
	i = 0;
	while (strs[0][i])
	{
		if (strs[len][i] != '1')
			error_crash(strs, s, "error wall\n", 0);
		i++;
	}
	return (0);
}

void	parse(t_map *info, char *name)
{
	char	*s;

	if (check_ext(name))
		exit(1);
	s = read_check(name);
	info->map = ft_split(s, '\n');
	if (!info->map)
		error_crash(info->map, s, "map vide\n", 1);
	if (is_rectangle(info->map, s) || is_wall(info->map, s) \
	|| check_elem(info->map, s))
		exit(1);
	info->copy = ft_split(s, '\n');
	if (!info->copy)
		error_crash(info->map, s, "allocation failed\n", 0);
	free(s);
	info->lx = ft_strlen(info->map[0]);
	info->ly = ft_nb_line(info->map);
	get_pos(info, info->map);
	info->nc = ft_count(info->map, 'C');
	if (!check_ff(info->copy, info->y, info->x))
		exit(memfree(info->map));
}

int	main(int ac, char **av)
{
	t_map	info;

	if (ac != 2)
		return (1);
	ft_memset(&info, 0, sizeof(info));
	parse(&info, av[1]);
	load_wind(&info);
}
