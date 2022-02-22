/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_buildmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:37:19 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/22 16:58:57 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_x(t_var *var, int y, char *map)
{
	int	i;
	int	x;

	i = -1;
	x = 0;
	while (map[++i] != '\n')
	{
		if (map[i] == '1')
			x += draw_wall(var, x, y);
		else if (map[i] == '0')
			x += draw_field(var, x, y);
		else if (map[i] == 'E')
			x += draw_exit(var, x, y);
		else if (map[i] == 'P')
			x += draw_player(var, x, y);
		else if (map[i] == 'C')
			x += draw_cons(var, x, y);
	}
}

void	sl_buildmap(t_var *var, char **map)
{
	unsigned int	i;

	i = 0;
	while (i < var->map_y)
	{
		draw_x(var, i * 63, map[i]);
		i++;
	}
}
