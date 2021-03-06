/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:39:07 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/03/03 17:09:53 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "gnl/get_next_line.h"
# include <unistd.h>
//# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define ESC_KEY 65307
# define A_KEY 97
# define W_KEY 119
# define S_KEY 115
# define D_KEY 100

// p_x/y describes the player position
// x = 0 & y = 0 left top corner
typedef struct s_var{
	void			*mlx;
	void			*win;
	void			*img;
	void			*tex_exit;
	int				exit_width;
	int				exit_height;
	void			*tex_player;
	int				player_width;
	int				player_height;
	void			*tex_field;
	int				field_width;
	int				field_height;
	void			*tex_wall;
	int				wall_width;
	int				wall_height;
	void			*tex_consum;
	int				consum_width;
	int				consum_height;
	unsigned int	map_x;
	unsigned int	map_y;
	int				check;
	int				flag_p;
	int				flag_c;
	int				flag_e;
	int				flag_1;
	int				flag_0;
	unsigned int	p_x;
	unsigned int	p_y;
	void			**map;
	unsigned int	moves;
	struct s_gnl	*gnl;
}	t_var;

// gnl pointers
typedef struct s_gnl{
	void	*build;
	void	*stat;
}	t_gnl;

t_gnl	*get_next_line(int fd);

void	sl_init(t_var *var, int *error);

void	check_map(t_var *var, char **map, int *error);

char	**store_map(t_var *var, char *map);

void	sl_loadtex(t_var *var);

void	sl_buildmap(t_var *var);

int		draw_wall(t_var *var, int x, int y);

int		draw_exit(t_var *var, int x, int y);

int		draw_field(t_var *var, int x, int y);

int		draw_player(t_var *var, int x, int y);

int		draw_cons(t_var *var, int x, int y);

void	sl_hook(t_var *var);

void	move_right(t_var *var, char **map);

void	move_left(t_var *var, char **map);

void	move_up(t_var *var, char **map);

void	move_down(t_var *var, char **map);

// void	print_map(char **map, unsigned int y);

int		close_window(t_var *var);

void	sl_driver(t_var *var);

#endif