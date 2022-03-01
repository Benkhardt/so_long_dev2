/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:24:14 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/25 17:31:13 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_error_free(t_var *var, char **map)
{
	unsigned int	i;

	i = 0;
	while (i < var->map_y)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	find_playerpos(t_var *var, char **map)
{
	unsigned int	x_i;
	unsigned int	y_i;

	x_i = 0;
	y_i = 0;
	while (y_i < var->map_y)
	{
		while (map[y_i][x_i] != '\n')
		{
			if (map[y_i][x_i] == 'P')
			{
				var->p_x = x_i;
				var->p_y = y_i;
			}
			x_i++;
		}
		x_i = 0;
		y_i++;
	}
}

static int	check_updown(t_var *var, char *line)
{
	int				i;
	unsigned int	length;

	i = -1;
	length = ft_strlen(line) - 1;
	if (length != var->map_x)
		return (-1);
	while (line[++i] != '\n')
		if (line[i] != '1')
			return (-1);
	return (0);
}

static int	check_line(t_var *var, char *line)
{
	unsigned int	i;
	unsigned int	length;

	i = 0;
	if (line[0] != '1')
		return (-1);
	while (line[++i] != '\n')
	{
		length = ft_strlen(line) - 1;
		if (length != var->map_x)
			return (-1);
		if (line[i] == 'P')
			var->flag_p++;
		else if (line[i] == 'C')
			var->flag_c++;
		else if (line[i] == 'E')
			var->flag_e++;
		else if (line[i] != '1' && line[i] != '0')
			return (-1);
	}
	if (line[i - 1] != '1')
		return (-1);
	return (0);
}

void	check_map(t_var *var, char **map, int *error)
{
	unsigned int	i;

	i = 0;
	if (check_updown(var, map[i]))
		error[0] = -1;
	while (++i < var->map_y)
	{
		error[0] = check_line(var, map[i]);
		if (error[0])
			break ;
	}
	if (check_updown(var, map[i - 1]))
		error[0] = -1;
	if (!(var->flag_c && var->flag_e && var->flag_p))
		error[0] = -1;
	find_playerpos(var, map);
	if (error[0] == -1)
		sl_error_free(var, map);
}
