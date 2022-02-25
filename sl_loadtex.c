/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_loadtex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:20:46 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/25 17:34:11 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_loadtex(t_var *var)
{
	var->tex_consum = mlx_xpm_file_to_image(var->mlx, \
	"./img/coll.xpm", &var->consum_width, &var->consum_height);
	var->tex_exit = mlx_xpm_file_to_image(var->mlx, \
	"./img/exit.xpm", &var->exit_width, &var->exit_height);
	var->tex_field = mlx_xpm_file_to_image(var->mlx, \
	"./img/floor.xpm", &var->field_width, &var->field_height);
	var->tex_player = mlx_xpm_file_to_image(var->mlx, \
	"./img/player.xpm", &var->player_width, &var->player_height);
	var->tex_wall = mlx_xpm_file_to_image(var->mlx, \
	"./img/wall.xpm", &var->wall_width, &var->wall_height);
}
