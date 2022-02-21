/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:24:14 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/22 00:18:48 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_updown(t_var *var, char *line)
{
	int	i;
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
	// unsigned int	length;

	i = 0;
	if (check_updown(var, map[i]))
		error[0] = -1;
	while (++i < var->map_y)
	{
		error[0] = check_line(var, map[i]);
		// error[0] = check_order(var, map[i]);
		if (error[0])
			break ;
	}
	if (check_updown(var, map[i - 1]))
		error[0] = -1;
	if (!(var->flag_c && var->flag_e && var->flag_p))
		error[0] = -1;
}
