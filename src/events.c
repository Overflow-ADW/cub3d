/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:03:33 by toadzima          #+#    #+#             */
/*   Updated: 2024/07/05 00:42:39 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_game(t_cubd *datas)
{
	free_all(datas);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_pressed(int key_code, t_cubd *datas)
{
	if (key_code == KEY_ESC)
		exit_game(datas);
	if (key_code == KEY_W)
		datas->player.up = 1;
	if (key_code == KEY_A)
		datas->player.left = 1;
	if (key_code == KEY_S)
		datas->player.down = 1;
	if (key_code == KEY_D)
		datas->player.right = 1;
	if (key_code == KEY_LEFT)
		datas->player.rot_left = 1;
	if (key_code == KEY_RIGHT)
		datas->player.rot_right = 1;
	return (0);
}

int	key_released(int key_code, t_cubd *datas)
{
	if (key_code == KEY_W)
		datas->player.up = 0;
	if (key_code == KEY_A)
		datas->player.left = 0;
	if (key_code == KEY_S)
		datas->player.down = 0;
	if (key_code == KEY_D)
		datas->player.right = 0;
	if (key_code == KEY_LEFT)
		datas->player.rot_left = 0;
	if (key_code == KEY_RIGHT)
		datas->player.rot_right = 0;
	return (0);
}
