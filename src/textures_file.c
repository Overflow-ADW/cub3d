/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toadzima <toadzima@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:31:56 by toadzima          #+#    #+#             */
/*   Updated: 2024/07/05 15:45:09 by toadzima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_format_text(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	if (i > 2)
		if (str[i--] == 'm')
			if (str[i--] == 'p')
				if (str[i--] == 'x')
					if (str[i--] == '.')
						return (0);
	return (1);
}

unsigned long	create_rgb(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}

static void	set_rgb_var(t_parsing *pars, int line, int texture_id)
{
	if (pars->file[line][0] == 'F' && pars->file[line][1] == ' ')
		pars->textures[4] = cub3d_strdup(cub3d_strtrim(pars->file[line]));
	else if (pars->file[line][0] == 'C' && pars->file[line][1] == ' ')
		pars->textures[5] = cub3d_strdup(cub3d_strtrim(pars->file[line]));
	texture_id++;
}

static void	set_textures_var(t_parsing *pars, int line, int texture_id)
{
	if (pars->file[line][0] == 'N' && pars->file[line][1] == 'O')
		pars->textures[0] = cub3d_strdup(cub3d_strtrim(pars->file[line]));
	else if (pars->file[line][0] == 'S' && pars->file[line][1] == 'O')
		pars->textures[1] = cub3d_strdup(cub3d_strtrim(pars->file[line]));
	else if (pars->file[line][0] == 'W' && pars->file[line][1] == 'E')
		pars->textures[2] = cub3d_strdup(cub3d_strtrim(pars->file[line]));
	else if (pars->file[line][0] == 'E' && pars->file[line][1] == 'A')
		pars->textures[3] = cub3d_strdup(cub3d_strtrim(pars->file[line]));
	texture_id++;
}

void	get_texture_from_file(t_parsing *pars)
{
	int	i;
	int	texture_id;

	i = 0;
	texture_id = 0;
	while (pars->file[i] && texture_id < 7)
	{
		if (pars->file[i][0] == 'N' || pars->file[i][0] == 'S'
			|| pars->file[i][0] == 'W' || pars->file[i][0] == 'E'
			|| pars->file[i][0] == 'S')
		{
			set_textures_var(pars, i, texture_id);
		}
		else if (pars->file[i][0] == 'F' || pars->file[i][0] == 'C')
		{
			set_rgb_var(pars, i, texture_id);
		}
		i++;
	}
}
