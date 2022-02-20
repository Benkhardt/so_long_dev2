/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:10:26 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/10/03 21:24:33 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*rtn;

	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	rtn = (char *)malloc(sizeof(char) * size + 2);
	while (s1[j])
	{
		rtn[i] = s1[j++];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		rtn[i] = s2[j++];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
