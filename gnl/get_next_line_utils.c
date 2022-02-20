/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:39:02 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/01/26 22:49:55 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int	gnl_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i++;
	}
	return (0);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*rtn;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (s1 == NULL)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	rtn = (char *)malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (rtn == NULL || s1 == NULL)
		return (NULL);
	while (s1[++i] != '\0' && s1)
		rtn[i] = s1[i];
	while (s2[j] != '\0' && s2)
		rtn[i++] = s2[j++];
	rtn[i] = '\0';
	free(s1);
	return (rtn);
}
