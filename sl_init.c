/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:06:14 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/03/01 15:27:09 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_init(t_var *var, int *error)
{
	var->exit_width = 0;
	var->exit_height = 0;
	var->player_height = 0;
	var->player_width = 0;
	var->field_height = 0;
	var->field_width = 0;
	var->wall_height = 0;
	var->wall_width = 0;
	var->consum_height = 0;
	var->consum_width = 0;
	var->map_x = 0;
	var->map_y = 0;
	var->check = 0;
	var->flag_0 = 0;
	var->flag_1 = 0;
	var->flag_c = 0;
	var->flag_e = 0;
	var->flag_p = 0;
	var->p_x = 0;
	var->p_y = 0;
	error[0] = 0;
}
