/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:03:01 by toadzima          #+#    #+#             */
/*   Updated: 2024/07/04 22:18:34 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_line_height(t_ray *ray, t_player player)
{
	if (ray->side == 0)
		ray->wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->wall_dist = ray->side_dist_y - ray->delta_dist_y;
	ray->line_height = (int)(S_HEIGHT / ray->wall_dist);
	ray->draw_start = (ray->line_height * -1) / 2 + S_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->side == 0)
		ray->wall_x = player.py + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = player.px + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

static int	get_texture_pixel(t_cubd *datas, t_ray *ray, int x, int y)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			return (datas->tx->w[SIZE * y + x]);
		else
			return (datas->tx->e[SIZE * y + x]);
	}
	else if (ray->dir_y > 0)
		return (datas->tx->s[SIZE * y + x]);
	return (datas->tx->n[SIZE * y + x]);
}

void	set_screen_pixels(t_cubd *datas, t_ray *ray, int x, int i)
{
	int		y;
	int		tx;
	int		ty;
	float	t_step;
	float	t_pos;

	tx = (int)(ray->wall_x * SIZE);
	if (ray->side == 0 && ray->dir_x < 0)
		tx = SIZE - tx - 1;
	else if (ray->side == 1 && ray->dir_y > 0)
		tx = SIZE - tx - 1;
	t_step = 1.0 * SIZE / ray->line_height;
	t_pos = (ray->draw_start - S_HEIGHT / 2 + ray->line_height / 2) * t_step;
	y = ray->draw_start - 1;
	while (++y < S_HEIGHT - 1 && ++i < ray->line_height)
	{
		ty = (int)t_pos & (SIZE - 1);
		t_pos += t_step;
		datas->pixels[y][x] = get_texture_pixel(datas, ray, tx, ty);
	}
}
