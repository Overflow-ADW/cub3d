/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:45:21 by fvastena          #+#    #+#             */
/*   Updated: 2024/07/05 12:45:22 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	free_tabs(void **tab, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
		ft_free(tab[i]);
	ft_free(tab);
}

void	mlx_free(t_cubd *datas)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (datas->mlx_imgs[i].ptr)
			mlx_destroy_image(datas->mlx_vars.mlx, datas->mlx_imgs[i].ptr);
	}
	if (datas->mlx_vars.mlx_win)
		mlx_destroy_window(datas->mlx_vars.mlx, datas->mlx_vars.mlx_win);
}

void	free_textures(char **textures, t_tx *tx)
{
	ft_free(textures[0]);
	ft_free(textures[1]);
	ft_free(textures[2]);
	ft_free(textures[3]);
	ft_free(textures[4]);
	ft_free(textures[5]);
	if (tx)
	{
		ft_free(tx->n);
		ft_free(tx->s);
		ft_free(tx->w);
		ft_free(tx->e);
		free(tx);
		tx = NULL;
	}
}
