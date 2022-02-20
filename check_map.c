/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:24:14 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/20 22:44:07 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_chars(t_var *var, char *line)
{
	unsigned int	i;
	unsigned int	length;

	i = 0;
	if (line[0] != '1')
		return (-1);
	while (line[++i] != '\n')
	{
		length = ft_strlen(line);
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
}

void	check_map(t_var *var, char **map, int *error)
{
	int	i;
	int	length;

	i = 0;
	// if first line other then 1 error = -1
	while (++i < var->map_y)
	{
		error[0] = check_chars(var, map[i]);
		error[0] = check_order(var, map[i]);
		if (error[0])
			break ;
	}
	// if last line other then 1 error = -1
}
