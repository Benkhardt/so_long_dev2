/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:00:48 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/22 00:28:08 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_var	var;
	char	**map;
	int		error;

	error = 0;
	// should init
	var.flag_0 = 0;
	var.flag_1 = 0;
	var.flag_c = 0;
	var.flag_e = 0;
	var.flag_p = 0;
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
		ft_putstr_fd("Error\n", 1);
		return (-3);
	}
	var.mlx = mlx_init();
	if (var.mlx == NULL)
		return (-4);
	var.win = mlx_new_window(var.mlx, var.map_x * 63, var.map_y * 63, "so_long");
	if (var.win == NULL)
		return (-4);
	mlx_loop(var.mlx);
}
