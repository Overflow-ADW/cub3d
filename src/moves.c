/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toadzima <toadzima@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:12:26 by toadzima          #+#    #+#             */
/*   Updated: 2024/07/01 15:12:28 by toadzima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_up(t_cubd *datas, t_player player)
{
	float	new_x;
	float	new_y;

	new_x = player.px + player.pdx;
	new_y = player.py + player.pdy;
	return (validate_move(datas, new_x, new_y));
}

int	move_down(t_cubd *datas, t_player player)
{
	float	new_x;
	float	new_y;

	new_x = player.px - player.pdx;
	new_y = player.py - player.pdy;
	return (validate_move(datas, new_x, new_y));
}

int	move_left(t_cubd *datas, t_player player)
{
	float	new_x;
	float	new_y;

	new_x = player.px + player.pdy;
	new_y = player.py - player.pdx;
	return (validate_move(datas, new_x, new_y));
}

int	move_right(t_cubd *datas, t_player player)
{
	float	new_x;
	float	new_y;

	new_x = player.px - player.pdy;
	new_y = player.py + player.pdx;
	return (validate_move(datas, new_x, new_y));
}
