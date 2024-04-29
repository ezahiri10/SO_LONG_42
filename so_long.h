/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:26:01 by ezahiri           #+#    #+#             */
/*   Updated: 2024/04/29 16:19:59 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include "libft/libft.h"

# define WALL "textures/WALL.xpm"
# define EXIT "textures/EXIT.xpm"
# define PLAYER "textures/PLAYER.xpm"
# define PLAYER_LEFT "textures/PLAYER_LEFT.xpm"
# define SPACE "textures/SPACE.xpm"
# define COLLECTIBLE "textures/COLLECTIBLE.xpm"

typedef struct s_map
{
	char	**map;
	char	**copy;
	void	*mlx;
	void	*win;
	void	*img;
	int		lx;
	int		ly;
	int		x;
	int		y;
	int		nc;
	int		move;
}	t_map;

char	*read_check(char *name);
int		memfree(char **strs);
int		check_elem(char **strs, char *s);
void	get_pos(t_map *info, char **strs);
int		ft_count(char **strs, char c);
int		check_ff(char **map, int y, int x);
void	load_wind(t_map *so);
int		error_crash(char **strs, char *s, char *err, char mod);
void	clear_mlx(t_map *so);
int		ft_nb_line(char **strs);
void	xpm_put(t_map *so, char *s, int y, int x);

#endif