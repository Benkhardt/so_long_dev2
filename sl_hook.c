/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:46:56 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/24 20:36:36 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_hook(int keycode, t_var *var, char **map)
{
	if (keycode == ESC_KEY)
		close_window(var);
	else if (keycode == A_KEY)
		move_left(var, map);
	else if (keycode == S_KEY)
		move_bottom(var, map);
	else if (keycode == D_KEY)
		move_right(var, map);
	else if (keycode == W_KEY)
		move_up(var, map);
	return (0);
}


// somehow have to get map stored to struct t_var...

void	sl_hook(t_var *var, char **map)
{
	mlx_key_hook(var->win, key_hook, var);
}
