/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_imgs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:30:30 by toadzima          #+#    #+#             */
/*   Updated: 2024/07/05 00:49:38 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*set_tx_values(t_cubd *datas, int i)
{
	int	*buf;
	int	y;
	int	x;

	buf = malloc(sizeof(int) * SIZE * SIZE);
	if (!buf)
		ft_errors(datas, E_MALLOC, "textures pixel buffer");
	ft_bzero(buf, SIZE * SIZE);
	y = 0;
	while (y < SIZE)
	{
		x = 0;
		while (x < SIZE)
		{
			buf[y * SIZE + x] = datas->mlx_imgs[i].addr[y * SIZE + x];
			x++;
		}
		y++;
	}
	return (buf);
}

static unsigned long	get_color(t_cubd *datas, char *raw_rgb)
{
	char			**rgb;
	unsigned long	full_rgb;

	rgb = ft_split(raw_rgb, ',');
	if (!rgb)
		ft_errors(datas, E_MALLOC, "RGB split");
	full_rgb = create_rgb(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	free_tabs((void **)rgb, 3);
	return (full_rgb);
}

static void	set_tx(t_cubd *datas)
{
	datas->tx = malloc(sizeof(t_tx));
	if (!datas->tx)
		ft_errors(datas, E_MALLOC, "textures t_tx struct");
	datas->tx->n = set_tx_values(datas, 0);
	datas->tx->s = set_tx_values(datas, 1);
	datas->tx->w = set_tx_values(datas, 2);
	datas->tx->e = set_tx_values(datas, 3);
	datas->tx->c_color = get_color(datas, datas->pars->textures[4]);
	datas->tx->f_color = get_color(datas, datas->pars->textures[5]);
}

void	set_mlx_imgs(t_cubd *datas)
{
	int	i;
	int	size;

	i = -1;
	size = SIZE;
	while (++i < 4)
	{
		datas->mlx_imgs[i].ptr = mlx_xpm_file_to_image(datas->mlx_vars.mlx,
				datas->pars->textures[i], &size, &size);
		if (!datas->mlx_imgs[i].ptr)
			ft_errors(datas, E_M_IMG, datas->pars->textures[i]);
		datas->mlx_imgs[i].addr = (int *)mlx_get_data_addr(
				datas->mlx_imgs[i].ptr, &datas->mlx_imgs[i].bpp,
				&datas->mlx_imgs[i].width, &datas->mlx_imgs[i].endian);
		if (!datas->mlx_imgs[i].addr)
			ft_errors(datas, E_M_ADDR, datas->pars->textures[i]);
	}
	set_tx(datas);
}

void	ft_init_s_img(t_img *s_img, t_cubd *datas)
{
	s_img->ptr = NULL;
	s_img->addr = NULL;
	s_img->width = 0;
	s_img->bpp = 0;
	s_img->endian = 0;
	s_img->ptr = mlx_new_image(datas->mlx_vars.mlx, S_WIDTH, S_HEIGHT);
	if (s_img->ptr == NULL)
		ft_errors(datas, E_M_IMG, "Screen image");
	s_img->addr = (int *)mlx_get_data_addr(s_img->ptr,
			&s_img->bpp, &s_img->width, &s_img->endian);
	if (s_img->addr == NULL)
		ft_errors(datas, E_M_ADDR, "Screen image addr");
}
