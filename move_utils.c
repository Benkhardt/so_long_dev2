/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:38:26 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/03/01 20:52:00 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	print_map(char **map, unsigned int y)
// {
// 	unsigned int	i;

// 	i = 0;
// 	while (i < y)
// 		if (map[i] != NULL)
// 			ft_putstr_fd(map[i++], 1);
// }

static void	check_move(int *move, t_var *var, char **map)
{
	int	x;
	int	y;

	x = var->p_x + move[0];
	y = var->p_y + move[1];
	if (map[y][x] == '1')
		var->check = 1;
	else if (map[y][x] == '0')
		var->check = 0;
	else if (map[y][x] == 'E' && var->flag_c)
		var->check = 1;
	else if (map[y][x] == 'E' && !var->flag_c)
		var->check = 3;
	else if (map[y][x] == 'C')
		var->check = 2;
}

void	move_up(t_var *var, char **map)
{
	int	move[2];

	move[0] = 0;
	move[1] = -1;
	check_move(move, var, map);
	if (var->check == 0 || var->check == 2)
	{
		mlx_put_image_to_window(var->mlx, var->win, \
		var->tex_player, var->p_x * 63, (var->p_y - 1) * 63);
		mlx_put_image_to_window(var->mlx, var->win, \
		var->tex_field, var->p_x * 63, var->p_y * 63);
	}
	else if (var->check == 1)
		return ;
	else if (var->check == 3)
		close_window(var);
	if (var->check == 2)
		var->flag_c--;
	var->p_y--;
	map[var->p_y][var->p_x] = 'P';
	map[var->p_y + 1][var->p_x] = '0';
	ft_putstr_fd("move up, total movements: ", 1);
	ft_putnbr_fd((int)++var->moves, 1);
	ft_putchar_fd('\n', 1);
}

void	move_down(t_var *var, char **map)
{
	int	move[2];

	move[0] = 0;
	move[1] = 1;
	check_move(move, var, map);
	if (var->check == 0 || var->check == 2)
	{
		mlx_put_image_to_window(var->mlx, var->win, \
		var->tex_player, var->p_x * 63, (var->p_y + 1) * 63);
		mlx_put_image_to_window(var->mlx, var->win, \
		var->tex_field, var->p_x * 63, var->p_y * 63);
	}
	else if (var->check == 1)
		return ;
	else if (var->check == 3)
		close_window(var);
	if (var->check == 2)
		var->flag_c--;
	var->p_y++;
	map[var->p_y][var->p_x] = 'P';
	map[var->p_y - 1][var->p_x] = '0';
	ft_putstr_fd("move down, total movements: ", 1);
	ft_putnbr_fd((int)++var->moves, 1);
	ft_putchar_fd('\n', 1);
}

void	move_left(t_var *var, char **map)
{
	int	move[2];

	move[0] = -1;
	move[1] = 0;
	check_move(move, var, map);
	if (var->check == 0 || var->check == 2)
	{
		mlx_put_image_to_window(var->mlx, var->win, \
		var->tex_player, (var->p_x - 1) * 63, var->p_y * 63);
		mlx_put_image_to_window(var->mlx, var->win, \
		var->tex_field, var->p_x * 63, var->p_y * 63);
	}
	else if (var->check == 1)
		return ;
	else if (var->check == 3)
		close_window(var);
	if (var->check == 2)
		var->flag_c--;
	var->p_x--;
	map[var->p_y][var->p_x] = 'P';
	map[var->p_y][var->p_x + 1] = '0';
	ft_putstr_fd("move left, total movements: ", 1);
	ft_putnbr_fd((int)++var->moves, 1);
	ft_putchar_fd('\n', 1);
}

void	move_right(t_var *var, char **map)
{
	int	move[2];

	move[0] = 1;
	move[1] = 0;
	check_move(move, var, map);
	if (var->check == 0 || var->check == 2)
	{
		mlx_put_image_to_window(var->mlx, var->win, \
		var->tex_player, (var->p_x + 1) * 63, var->p_y * 63);
		mlx_put_image_to_window(var->mlx, var->win, \
		var->tex_field, var->p_x * 63, var->p_y * 63);
	}
	else if (var->check == 1)
		return ;
	else if (var->check == 3)
		close_window(var);
	if (var->check == 2)
		var->flag_c--;
	var->p_x++;
	map[var->p_y][var->p_x] = 'P';
	map[var->p_y][var->p_x - 1] = '0';
	ft_putstr_fd("move right, total movements: ", 1);
	ft_putnbr_fd((int)++var->moves, 1);
	ft_putchar_fd('\n', 1);
}
