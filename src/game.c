/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:05:59 by toadzima          #+#    #+#             */
/*   Updated: 2024/07/04 23:04:52 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_mlx_vars(t_cubd *datas)
{
	datas->mlx_vars.mlx = mlx_init();
	if (!datas->mlx_vars.mlx)
		ft_errors(datas, E_M_INIT, NULL);
	datas->mlx_vars.mlx_win = mlx_new_window(datas->mlx_vars.mlx,
			S_WIDTH, S_HEIGHT, "Cub3d");
	if (!datas->mlx_vars.mlx_win)
		ft_errors(datas, E_M_WIN, NULL);
}

static void	move_player(t_cubd *datas)
{
	datas->player.pdx = datas->player.dir_x * MOVE_SPEED;
	datas->player.pdy = datas->player.dir_y * MOVE_SPEED;
	if (datas->player.down == 1)
		move_down(datas, datas->player);
	if (datas->player.up == 1)
		move_up(datas, datas->player);
	if (datas->player.left == 1)
		move_left(datas, datas->player);
	if (datas->player.right == 1)
		move_right(datas, datas->player);
	if (datas->player.rot_left == 1)
		rotate_left(&(datas->player));
	if (datas->player.rot_right == 1)
		rotate_right(&(datas->player));
}

static int	game_loop(t_cubd *datas)
{
	move_player(datas);
	render_screen(datas);
	return (0);
}

int	cub3d_game(t_cubd *datas)
{
	set_player_infos(datas);
	init_mlx_vars(datas);
	set_mlx_imgs(datas);
	render_screen(datas);
	mlx_hook(datas->mlx_vars.mlx_win, 17, 0, exit_game, datas);
	mlx_hook(datas->mlx_vars.mlx_win, 2, (1L << 0), key_pressed, datas);
	mlx_hook(datas->mlx_vars.mlx_win, 3, (1L << 1), key_released, datas);
	mlx_loop_hook(datas->mlx_vars.mlx, game_loop, datas);
	mlx_loop(datas->mlx_vars.mlx);
	return (0);
}
