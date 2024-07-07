/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:00:23 by toadzima          #+#    #+#             */
/*   Updated: 2024/07/04 22:26:03 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_pixels(int **pixels)
{
	int	i;
	int	j;

	i = 0;
	while (i < S_HEIGHT)
	{
		j = 0;
		while (j < S_WIDTH)
		{
			pixels[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	init_screen_pixels(t_cubd *datas)
{
	int	i;

	if (!datas->pixels)
	{
		datas->pixels = ft_calloc(1, sizeof(int *) * S_HEIGHT);
		if (!datas->pixels)
			ft_errors(datas, E_MALLOC, "datas->pixels");
		i = 0;
		while (i < S_HEIGHT)
		{
			datas->pixels[i] = ft_calloc(1, sizeof(int *) * S_WIDTH);
			if (!datas->pixels[i])
				ft_errors(datas, E_MALLOC, "datas->pixels[i]");
			i++;
		}
	}
	set_pixels(datas->pixels);
}

void	set_simg_pixels(t_img *s_img, int x, int y, int color)
{
	int	pix_pos;

	pix_pos = y * (s_img->width / 4) + x;
	s_img->addr[pix_pos] = color;
}

void	render_sframe(t_cubd *datas)
{
	t_img	s_img;
	int		x;
	int		y;

	ft_init_s_img(&s_img, datas);
	y = 0;
	while (y < S_HEIGHT)
	{
		x = 0;
		while (x < S_WIDTH)
		{
			if (datas->pixels[y][x] > 0)
				set_simg_pixels(&s_img, x, y, datas->pixels[y][x]);
			else if (y < S_HEIGHT / 2)
				set_simg_pixels(&s_img, x, y, datas->tx->c_color);
			else if (y < S_HEIGHT - 1)
				set_simg_pixels(&s_img, x, y, datas->tx->f_color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(datas->mlx_vars.mlx,
		datas->mlx_vars.mlx_win, s_img.ptr, 0, 0);
	mlx_destroy_image(datas->mlx_vars.mlx, s_img.ptr);
}

void	render_screen(t_cubd *datas)
{
	init_screen_pixels(datas);
	init_ray(&(datas->ray), datas, 0, 0);
	raycasting(datas);
	render_sframe(datas);
}
