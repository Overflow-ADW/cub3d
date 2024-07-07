/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:37:20 by toadzima          #+#    #+#             */
/*   Updated: 2024/07/07 19:03:14 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_pos_wall_collision(t_cubd *data, double x, double y)
{
	if (data->pars->map[(int)y][(int)x] == '0')
		return (0);
	return (1);
}

static int	is_valid_pos_in_map(t_cubd *data, double x, double y)
{
	if (x < 0.25 || x >= data->pars->real_width - 1.25)
		return (1);
	if (y < 0.25 || y >= data->pars->map_height - 0.25)
		return (1);
	return (0);
}

static int	is_valid_pos(t_cubd *data, double x, double y)
{
	if (is_valid_pos_in_map(data, x, y))
		return (0);
	if (is_valid_pos_wall_collision(data, x, y))
		return (0);
	return (1);
}

int	validate_move(t_cubd *data, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (is_valid_pos(data, new_x, data->player.py))
	{
		data->player.px = new_x;
		moved = 1;
	}
	if (is_valid_pos(data, data->player.px, new_y))
	{
		data->player.py = new_y;
		moved = 1;
	}
	return (moved);
}
