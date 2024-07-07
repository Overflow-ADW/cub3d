/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:11:50 by toadzima          #+#    #+#             */
/*   Updated: 2024/07/04 23:16:08 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_pdir(t_player *player)
{
	if (player->orientation == 'N' || player->orientation == 'S')
	{
		player->dir_y = -1;
		player->plane_x = FOV;
		player->plane_y = 0;
		player->dir_x = 0;
	}
	if (player->orientation == 'S')
	{
		player->dir_y = 1;
		player->plane_x = -FOV;
	}
	if (player->orientation == 'W' || player->orientation == 'E')
	{
		player->dir_x = -1;
		player->plane_y = -FOV;
		player->dir_y = 0;
		player->plane_x = 0;
	}
	if (player->orientation == 'E')
	{
		player->dir_x = 1;
		player->plane_y = FOV;
	}
}

static void	set_player_pos(t_player *pl, char **map)
{
	int	j;
	int	i;

	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (ft_strchr("NSEW", map[j][i]))
			{
				pl->px = i + 0.5;
				pl->py = j + 0.5;
				pl->orientation = map[j][i];
				map[j][i] = '0';
				break ;
			}
		}
	}
}

void	set_player_infos(t_cubd *datas)
{
	set_player_pos(&(datas->player), datas->pars->map);
	datas->player.pdx = 0;
	datas->player.pdy = 0;
	datas->player.up = 0;
	datas->player.down = 0;
	datas->player.left = 0;
	datas->player.right = 0;
	datas->player.rot_left = 0;
	datas->player.rot_right = 0;
	set_pdir(&datas->player);
}
