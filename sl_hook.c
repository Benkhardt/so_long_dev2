/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:46:56 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/03/01 13:36:33 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_var *var)
{
	unsigned int	i;

	i = 0;
	while (i < var->map_y)
		free(var->map[i++]);
	free(var->map);
	mlx_destroy_image(var->mlx, var->tex_consum);
	mlx_destroy_image(var->mlx, var->tex_exit);
	mlx_destroy_image(var->mlx, var->tex_field);
	mlx_destroy_image(var->mlx, var->tex_player);
	mlx_destroy_image(var->mlx, var->tex_wall);
	mlx_clear_window(var->mlx, var->win);
	mlx_destroy_window(var->mlx, var->win);
	mlx_destroy_display(var->mlx);
	mlx_loop_end(var->mlx);
	free(var->mlx);
	exit(0);
}

static int	key_hook(int keycode, t_var *var)
{
	if (keycode == ESC_KEY)
		close_window(var);
	else if (keycode == A_KEY)
		move_left(var, (char **)var->map);
	else if (keycode == S_KEY)
		move_down(var, (char **)var->map);
	else if (keycode == D_KEY)
		move_right(var, (char **)var->map);
	else if (keycode == W_KEY)
		move_up(var, (char **)var->map);
	return (0);
}

void	sl_hook(t_var *var)
{
	mlx_key_hook(var->win, key_hook, var);
	mlx_hook(var->win, 17, (1L << 17), close_window, var);
}
