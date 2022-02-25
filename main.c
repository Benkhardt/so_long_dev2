/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:00:48 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/25 18:43:02 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_var	var;
	int		error;

	sl_init(&var, &error);
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	var.map = (void **)store_map(&var, argv[1]);
	if (var.map == NULL)
	{
		ft_putstr_fd("Error\n", 1);
		return (-2);
	}
	check_map(&var, (char **)var.map, &error);
	if (error)
	{
		ft_putstr_fd("Error\n", 1);
		return (-3);
	}
	sl_driver(&var);
}
