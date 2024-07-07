/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toadzima <toadzima@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:08:27 by toadzima          #+#    #+#             */
/*   Updated: 2024/07/05 15:50:53 by toadzima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_map_char(char c)
{
	if (c == ' ' || c == '\n' || c == '\0')
		return (1);
	else if (c == '1')
		return (2);
	else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (3);
	else if (c == '0')
		return (4);
	else
		return (0);
}

int	ft_check_inside_map(t_parsing *pars, int i, int j, int cpy)
{
	int	len;
	int	cpy_i;
	int	cpy_j;

	if (ft_check_side(pars, i, j))
		return (1);
	cpy_j = j;
	cpy_i = i;
	if (j > 0)
		j--;
	if (i > 0)
		i--;
	while (j < pars->map_height && j < (cpy_j + 2))
	{
		len = cub3d_strlen(pars->map[j]);
		i = cpy;
		while (i < len && i < (cpy_i + 2))
		{
			if (ft_check_map_char(pars->map[j][i]) < 2)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_is_map_closed(t_parsing *pars)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (j <= pars->map_height)
	{
		i = 0;
		len = cub3d_strlen(pars->map[j]);
		while (i < len)
		{
			if (ft_check_map_char(pars->map[j][i]) > 2)
			{
				if (ft_check_inside_map(pars, i, j, i))
					return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

void	ft_check_text(t_cubd *datas)
{
	int	i;
	int	fd;

	i = 0;
	while (i < 4)
	{
		fd = open(datas->pars->textures[i], O_RDONLY);
		if (fd == -1)
			ft_errors(datas, E_PATH_TEXT, datas->pars->textures[i]);
		if (ft_check_format_text(datas->pars->textures[i]))
			ft_errors(datas, E_ERR_END_TXT, datas->pars->textures[i]);
		close(fd);
		i++;
	}
}


int	ft_parsing(char *str, t_cubd *datas)
{
	if (ft_check_format(str))
		ft_errors(datas, E_FORMAT, NULL);
	datas->pars->file = ft_stock_file(str, datas, datas->pars);
	if (!datas->pars->file)
		ft_errors(datas, E_MALLOC, "During GNL");
	if (ft_check_file(datas, datas->pars))
		ft_errors(datas, E_MALLOC, "pars->file");
	ft_clean_map(datas->pars);
	ft_check_text(datas);
	return (0);
}
