/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:38:26 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/25 16:40:37 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_map(char **map, unsigned int y)
{
	unsigned int	i;

	i = 0;
	while (i < y)
		if (map[i] != NULL)
			ft_putstr_fd(map[i++], 1);
}

static void	check_move(int *move, int *check, t_var *var, char **map)
{
	int	x;
	int	y;

	x = var->p_x + move[0];
	y = var->p_y + move[1];
	if (map[y][x] == '1')
		check[0] = 1;
	else if (map[y][x] == '0')
		check[0] = 0;
	else if (map[y][x] == 'E' && var->flag_c)
		check[0] = 1;
	else if (map[y][x] == 'E' && !var->flag_c)
		check[0] = 3;
	else if (map[y][x] == 'C')
		check[0] = 2;
}

void	move_up(t_var *var, char **map)
{
	int	check;
	int	move[2];

	check = -1;
	move[0] = 0; // x, nothing happens to x if we move up
	move[1] = -1; // y, we moving up
	check_move(move, &check, var, map);
	if (check == 0) // field
	{
		mlx_put_image_to_window(var->mlx, var->win, var->tex_player, var->p_x * 63, (var->p_y - 1) * 63);
		mlx_put_image_to_window(var->mlx, var->win, var->tex_field, var->p_x * 63, var->p_y * 63);
		map[var->p_y][var->p_x] = '0';
	}
	else if (check == 1) // wall or exit if still consumables available on map (flag_c > 0)
		return ;
	else if (check == 2) // coll
	{
		mlx_put_image_to_window(var->mlx, var->win, var->tex_player, var->p_x * 63, (var->p_y - 1) * 63);
		mlx_put_image_to_window(var->mlx, var->win, var->tex_field, var->p_x * 63, var->p_y * 63);
		var->flag_c--;
		map[var->p_y][var->p_x] = '0';
	}
	else if (check == 3)
	 	close_window(var);
	var->p_y--;
	map[var->p_y][var->p_x] = 'P';
	print_map(map, var->map_y);
	ft_putnbr_fd(var->flag_c, 1);
	ft_putchar_fd('\n', 1);
}

void	move_down(t_var *var, char **map)
{
	int	check;
	int	move[2];

	check = -1;
	move[0] = 0; // x, nothing happens to x if we move up
	move[1] = 1; // y, we moving up
	check_move(move, &check, var, map);
	if (check == 0) // field
	{
		mlx_put_image_to_window(var->mlx, var->win, var->tex_player, var->p_x * 63, (var->p_y + 1) * 63);
		mlx_put_image_to_window(var->mlx, var->win, var->tex_field, var->p_x * 63, var->p_y * 63);
		map[var->p_y][var->p_x] = '0';
	}
	else if (check == 1) // wall or exit if still consumables available on map (flag_c > 0)
		return ;
	else if (check == 2) // coll
	{
		mlx_put_image_to_window(var->mlx, var->win, var->tex_player, var->p_x * 63, (var->p_y + 1) * 63);
		mlx_put_image_to_window(var->mlx, var->win, var->tex_field, var->p_x * 63, var->p_y * 63);
		var->flag_c--;
		map[var->p_y][var->p_x] = '0';
	}
	else if (check == 3)
	 	close_window(var);
	var->p_y++;
	map[var->p_y][var->p_x] = 'P';
	print_map(map, var->map_y);
}

void	move_left(t_var *var, char **map)
{
	int	check;
	int	move[2];

	check = -1;
	move[0] = -1; // x, nothing happens to x if we move up
	move[1] = 0; // y, we moving up
	check_move(move, &check, var, map);
	if (check == 0) // field
	{
		mlx_put_image_to_window(var->mlx, var->win, var->tex_player, (var->p_x - 1) * 63, var->p_y * 63);
		mlx_put_image_to_window(var->mlx, var->win, var->tex_field, var->p_x * 63, var->p_y * 63);
		map[var->p_y][var->p_x] = '0';
	}
	else if (check == 1) // wall or exit if still consumables available on map (flag_c > 0)
		return ;
	else if (check == 2) // coll
	{
		mlx_put_image_to_window(var->mlx, var->win, var->tex_player, (var->p_x - 1) * 63, var->p_y * 63);
		mlx_put_image_to_window(var->mlx, var->win, var->tex_field, var->p_x * 63, var->p_y * 63);
		var->flag_c--;
		map[var->p_y][var->p_x] = '0';
	}
	else if (check == 3)
	 	close_window(var);
	var->p_x--;
	map[var->p_y][var->p_x] = 'P';
	print_map(map, var->map_y);
}

void	move_right(t_var *var, char **map)
{
	int	check;
	int	move[2];

	check = -1;
	move[0] = 1; // x, nothing happens to x if we move up
	move[1] = 0; // y, we moving up
	check_move(move, &check, var, map);
	if (check == 0) // field
	{
		mlx_put_image_to_window(var->mlx, var->win, var->tex_player, (var->p_x + 1) * 63, var->p_y * 63);
		mlx_put_image_to_window(var->mlx, var->win, var->tex_field, var->p_x * 63, var->p_y * 63);
		map[var->p_y][var->p_x] = '0';
	}
	else if (check == 1) // wall or exit if still consumables available on map (flag_c > 0)
		return ;
	else if (check == 2) // coll
	{
		mlx_put_image_to_window(var->mlx, var->win, var->tex_player, (var->p_x + 1) * 63, var->p_y * 63);
		mlx_put_image_to_window(var->mlx, var->win, var->tex_field, var->p_x * 63, var->p_y * 63);
		var->flag_c--;
		map[var->p_y][var->p_x] = '0';
	}
	else if (check == 3)
	 	close_window(var);
	var->p_x++;
	map[var->p_y][var->p_x] = 'P';
	print_map(map, var->map_y);
}
