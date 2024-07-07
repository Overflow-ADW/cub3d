/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:00:41 by toadzima          #+#    #+#             */
/*   Updated: 2024/07/07 19:03:08 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_ray_new_values(t_ray *ray, t_cubd *datas, int i)
{
	ray->camera_x = 2.0 * i / S_WIDTH - 1;
	ray->dir_x = datas->player.dir_x + datas->player.plane_x * ray->camera_x;
	ray->dir_y = datas->player.dir_y + datas->player.plane_y * ray->camera_x;
	ray->map_x = (int)datas->player.px;
	ray->map_y = (int)datas->player.py;
	ray->delta_dist_x = fabs(1 / datas->ray.dir_x);
	ray->delta_dist_y = fabs(1 / datas->ray.dir_y);
}

void	init_ray(t_ray *ray, t_cubd *datas, int trigger, int i)
{
	ray->camera_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->delta_dist_y = 0;
	ray->delta_dist_x = 0;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->wall_dist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	if (trigger == 1)
		set_ray_new_values(ray, datas, i);
}

void	init_side_dist(t_ray *ray, t_player player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player.px - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player.px) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player.py - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player.py) * ray->delta_dist_y;
	}
}

void	perform_dda(t_ray *ray, t_parsing *pars)
{
	int		hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25 || ray->map_x < 0.25)
			break ;
		else if ((ray->map_y > pars->map_height - 0.25) || \
				(ray->map_x > pars->real_width - 1.25))
			break ;
		else if (pars->map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

void	raycasting(t_cubd *datas)
{
	int	i;

	i = 0;
	while (i < S_WIDTH)
	{
		init_ray(&(datas->ray), datas, 1, i);
		init_side_dist(&(datas->ray), datas->player);
		perform_dda(&(datas->ray), datas->pars);
		get_line_height(&(datas->ray), datas->player);
		set_screen_pixels(datas, &(datas->ray), i, -1);
		i++;
	}
}
