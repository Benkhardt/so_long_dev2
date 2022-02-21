/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:10:24 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/22 00:15:44 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_x(char *map)
{
	int		fd;
	int		count;
	char	buffer[1];

	fd = open(map, O_RDONLY);
	count = 0;
	while (read(fd, &buffer, 1) && buffer[0] != '\n')
		count++;
	close(fd);
	return (count);
}

static int	get_y(char *map)
{
	int		fd;
	int		count;
	char	buffer[1];

	fd = open(map, O_RDONLY);
	if (fd < 1)
		return (0);
	count = 0;
	while (read(fd, &buffer, 1))
	{
		if (buffer[0] == '\n')
			count++;
	}
	close(fd);
	return (count);
}

static char	**store(char **rtn, char *map, t_var *var)
{
	unsigned int	i;
	int				fd;

	i = 0;
	fd = open(map, O_RDONLY);
	while (i < var->map_y)
	{
		var->gnl = get_next_line(fd);
		rtn[i] = (char *)var->gnl->build;
		i++;
	}
	close(fd);
	//free(var->gnl->stat);
	return (rtn);
}

char	**store_map(t_var *var, char *map)
{
	char	**rtn;

	var->map_y = get_y(map);
	if (var->map_y == 0)
		return (NULL);
	var->map_x = get_x(map);
	rtn = malloc(sizeof(char *) * var->map_y);
	if (rtn == NULL)
		return (NULL);
	rtn = store(rtn, map, var);
	return (rtn);
}
