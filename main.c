/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:00:48 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/19 21:25:56 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_var	var;
	char	**map;
	int		error;


	error = 0;
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
}