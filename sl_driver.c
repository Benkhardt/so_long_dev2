/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_driver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:34:35 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/25 18:43:44 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_driver(t_var *var)
{
	var->mlx = mlx_init();
	if (var->mlx == NULL)
		return ;
	sl_loadtex(var);
	var->win = mlx_new_window(var->mlx, var->map_x * 63, \
	var->map_y * 63, "so_long");
	if (var->win == NULL)
		return ;
	sl_buildmap(var);
	sl_hook(var);
	mlx_loop(var->mlx);
}
