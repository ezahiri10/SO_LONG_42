/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:45:40 by ezahiri           #+#    #+#             */
/*   Updated: 2024/04/09 02:39:33 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_exit(int fd, char *s, char *all)
{
	write (2, "invalid map\n", 12);
	close (fd);
	free(s);
	free(all);
	exit(1);
}

int	ft_check(char *s)
{
	int	len;

	len = ft_strlen (s) - 1;
	if (s[0] != '1')
		return (0);
	else if (s[len] == '\n' && s[len - 1] != '1')
		return (0);
	else if (s[len] != '\n' && s[len] != '1')
		return (0);
	else if (!(ft_strspn(s, "01PCEN\n") == ft_strlen(s)))
		return (0);
	return (1);
}

int	check_elem(char **strs, char *s)
{
	if (ft_count(strs, 'P') != 1)
		error_crash(strs, s, "error player\n", 0);
	else if (ft_count(strs, 'E') != 1)
		error_crash(strs, s, "error exit\n", 0);
	else if (ft_count(strs, 'C') < 1)
		error_crash(strs, s, "error collictibl\n", 0);
	return (0);
}

char	*read_check(char *name)
{
	int		fd;
	char	*s;
	char	*all;

	all = NULL;
	fd = open(name, O_RDONLY);
	if (fd == -1)
		exit(2);
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		ft_printf ("ssss\n");
		if (!ft_check(s))
		{
			get_next_line(-1);
			ft_exit(fd, s, all);
		}
		all = ft_strjoin(all, s);
		if (!all)
			ft_exit(fd, s, get_next_line(-1));
		free(s);
	}
	close(fd);
	return (all);
}
