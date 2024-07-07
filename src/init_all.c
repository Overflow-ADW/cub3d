/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsTemp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:34:27 by toadzima          #+#    #+#             */
/*   Updated: 2024/07/04 23:05:26 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_pars_tx(t_parsing *pars)
{
	pars->textures[0] = NULL;
	pars->textures[1] = NULL;
	pars->textures[2] = NULL;
	pars->textures[3] = NULL;
	pars->textures[4] = NULL;
	pars->textures[5] = NULL;
}

static void	init_mlx_imgs(t_cubd *datas)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		datas->mlx_imgs[i].ptr = NULL;
		datas->mlx_imgs[i].addr = NULL;
		datas->mlx_imgs[i].bpp = 0;
		datas->mlx_imgs[i].width = 0;
		datas->mlx_imgs[i].endian = 0;
	}
}

void	init_all(t_cubd *datas)
{
	int	i;

	datas->pars = malloc(sizeof(t_parsing));
	if (!datas->pars)
		ft_errors(datas, E_MALLOC, "pars struct");
	i = -1;
	while (++i < 6)
		datas->pars->is_valid[i] = 0;
	init_pars_tx(datas->pars);
	datas->pars->height = 0;
	datas->pars->map_height = 0;
	datas->pars->x = 0;
	datas->pars->file = NULL;
	datas->pars->map = NULL;
	datas->pixels = NULL;
	datas->screen.ptr = NULL;
	datas->mlx_vars.mlx = NULL;
	datas->mlx_vars.mlx_win = NULL;
	datas->pixels = NULL;
	datas->tx = NULL;
	init_mlx_imgs(datas);
}
