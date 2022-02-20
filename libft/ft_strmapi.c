/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:11:40 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/10/03 21:24:56 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*rtn;

	i = 0;
	rtn = ft_strdup(s);
	if (!rtn)
		return (NULL);
	while (rtn[i])
	{
		rtn[i] = (*f)(i, rtn[i]);
		i++;
	}
	return (rtn);
}
