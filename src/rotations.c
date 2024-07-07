/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toadzima <toadzima@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:22:01 by toadzima          #+#    #+#             */
/*   Updated: 2024/07/01 15:22:17 by toadzima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate(t_player *player, float rot_speed)
{
	float	tmp_x;

	tmp_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rot_speed)
		- player->dir_y * sin(rot_speed);
	player->dir_y = tmp_x * sin(rot_speed) + player->dir_y * cos(rot_speed);
	tmp_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_speed)
		- player->plane_y * sin(rot_speed);
	player->plane_y = tmp_x * sin(rot_speed) + player->plane_y * cos(rot_speed);
}

void	rotate_left(t_player *player)
{
	float	rot_speed;

	rot_speed = ROT_SPEED * -1;
	rotate(player, rot_speed);
}

void	rotate_right(t_player *player)
{
	float	rot_speed;

	rot_speed = ROT_SPEED;
	rotate(player, rot_speed);
}
