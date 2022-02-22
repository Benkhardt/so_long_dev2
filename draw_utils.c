/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:54:40 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/22 16:59:44 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_wall(t_var *var, int x, int y)
{
	mlx_put_image_to_window(var->mlx, var->win, var->tex_wall, x, y);
	return (63);
}

int	draw_exit(t_var *var, int x, int y)
{
	mlx_put_image_to_window(var->mlx, var->win, var->tex_exit, x, y);
	return (63);
}

int	draw_field(t_var *var, int x, int y)
{
	mlx_put_image_to_window(var->mlx, var->win, var->tex_field, x, y);
	return (63);
}

int	draw_player(t_var *var, int x, int y)
{
	mlx_put_image_to_window(var->mlx, var->win, var->tex_player, x, y);
	return (63);
}

int	draw_cons(t_var * var, int x, int y)
{
	mlx_put_image_to_window(var->mlx, var->win, var->tex_consum, x, y);
	return (63);
}
