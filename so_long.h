/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:39:07 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/24 21:11:02 by dbenkhar         ###   ########.fr       */
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

# define ESC_KEY 65307
# define A_KEY 97
# define W_KEY 119
# define S_KEY 115
# define D_KEY 100

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
	unsigned int	map_x;
	unsigned int	map_y;
	int		size_check;
	int		flag_p;
	int		flag_c;
	int		flag_e;
	int		flag_1;
	int		flag_0;
	unsigned int	p_x;
	unsigned int	p_y;
	struct s_gnl	*gnl;
}	t_var;

// gnl pointers
typedef struct	s_gnl{
	void	*build;
	void	*stat;
}	t_gnl;

t_gnl	*get_next_line(int fd);

void	sl_init(t_var *var, int *error);

void	check_map(t_var *var, char **map, int *error);

char	**store_map(t_var *var, char *map);

void	sl_loadtex(t_var *var);

void	sl_buildmap(t_var *var, char **map);

int		draw_wall(t_var *var, int x, int y);

int		draw_exit(t_var *var, int x, int y);

int		draw_field(t_var *var, int x, int y);

int		draw_player(t_var *var, int x, int y);

int		draw_cons(t_var * var, int x, int y);

#endif