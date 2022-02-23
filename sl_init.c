/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:06:14 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/23 20:53:37 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_init(t_var *var, int *error)
{
	var->exit_width = 0;
	var->exit_height = 0;
	var->player_height = 0;
	var->player_width = 0;
	var->ppos_x = 0;
	var->ppos_y = 0;
	var->field_height = 0;
	var->field_width = 0;
	var->wall_height = 0;
	var->wall_width = 0;
	var->consum_height =0;
	var->consum_width = 0;
	var->map_x = 0;
	var->map_y = 0;
	var->size_check = 0;
	var->flag_0 = 0;
	var->flag_1 = 0;
	var->flag_c = 0;
	var->flag_e = 0;
	var->flag_p = 0;
	var->player_x = 0;
	var->player_y = 0;
	error[0] = 0;
}

/*
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
	unsigned int		map_x;
	unsigned int		map_y;
	int		size_check;
	int		flag_p;
	int		flag_c;
	int		flag_e;
	int		flag_1;
	int		flag_0;
	struct s_gnl	*gnl;
*/