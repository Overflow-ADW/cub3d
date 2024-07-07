/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:04:26 by toadzima          #+#    #+#             */
/*   Updated: 2024/07/05 12:45:11 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all(t_cubd *datas)
{
	if (datas->pars)
	{
		if (datas->pars->x > 0)
			free_tabs((void **)datas->pars->file, datas->pars->x);
		if (datas->pars->map_height > 0)
			free_tabs((void **)datas->pars->map, datas->pars->map_height);
		free_textures(datas->pars->textures, datas->tx);
		free(datas->pars);
	}
	if (datas->pixels)
		free_tabs((void **)datas->pixels, S_HEIGHT);
	mlx_free(datas);
}

void	ft_free_parsing(t_parsing *pars)
{
	if (pars)
	{
		if (pars->x > 0)
			free_tabs((void **)pars->file, pars->x);
		if (pars->map_height > 0)
			free_tabs((void **)pars->map, pars->map_height);
		free(pars);
	}
}
