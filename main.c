/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:00:48 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/23 20:59:20 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_var	var;
	char	**map;
	int		error;

	sl_init(&var, &error);
	if (argc != 2)
	{
		ft_putstr_fd("too few arguments\n", 1);
		return (-1);
	}
	var.size_check = 0;
	map = store_map(&var, argv[1]);
	if (map == NULL)
	{
		ft_putstr_fd("can't find map file (failed to load fd)\n", 1);
		return (-2);
	}
	check_map(&var, map, &error);
	if (error)
	{
		ft_putstr_fd("invalid map\n", 1);
		return (-3);
	}
	printf("x(%d) y(%d)\n", var.player_x, var.player_y);
	var.mlx = mlx_init();
	if (var.mlx == NULL)
		return (-4);
	sl_loadtex(&var);
	var.win = mlx_new_window(var.mlx, var.map_x * 63, var.map_y * 63, "so_long");
	if (var.win == NULL)
		return (-4);
	sl_buildmap(&var, map);
	mlx_loop(var.mlx);
}
