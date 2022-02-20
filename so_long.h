/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:39:07 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/19 21:25:40 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "gnl/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

// ppos_x/y describes the player position
// x = 0 & y = 0 left top corner
typedef struct	s_var{
	void	*mlx;
	void	*win;
	void	*img;
	void	*tex_exit;
	int		exit_width;
	int		exit_height;
	void	*tex_player;
	int		player_width;
	int		player_height;
	int		ppos_x;
	int		ppos_y;
	void	*tex_field;
	int		field_width;
	int		field_height;
	void	*tex_wall;
	int		wall_width;
	int		wall_height;
	void	*tex_consum;
	int		consum_width;
	int		consum_height;
	int		map_x;
	int		map_y;
	int		size_check;
	t_gnl	*gnl;
}	t_var;

// gnl pointers
typedef struct	s_gnl{
	void	*build;
	void	*stat;
}	t_gnl;

t_gnl	*get_next_line(int fd);

void	check_map(t_var *var, char **map, int *error);

char	**store_map(t_var *var, char *map);

#endif