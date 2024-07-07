/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toadzima <toadzima@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:04:11 by toadzima          #+#    #+#             */
/*   Updated: 2024/07/05 15:26:21 by toadzima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_rgb_arg(t_cubd *datas, int j, int i)
{
	if (!datas->pars->file[j][i + 1]
		|| ft_is_num(datas->pars->file[j][i + 1]) != 0
		|| ft_is_num(datas->pars->file[j][i - 1]) != 0)
		ft_errors(datas, E_ARG_RGB, NULL);
}

int	ft_is_num(char c)
{
	if ((c >= 48 && c <= 57))
		return (0);
	return (1);
}

void	ft_clean_end_map(t_parsing *pars)
{
	int	check;
	int	i;

	check = 0;
	while (check == 0 && pars->height > pars->end_args)
	{
		i = 0;
		while (pars->file[pars->height - 1][i])
		{
			if (ft_iswhitespace(pars->file[pars->height - 1], i) != 0
				&& pars->file[pars->height - 1][i] != '\n')
			{
				check++;
				break ;
			}
			i++;
		}
		if (!check)
			pars->height--;
	}
}

int	ft_clean_map(t_parsing *pars)
{
	int	i;
	int	check;

	check = 0;
	while (check == 0 && pars->end_args < pars->height)
	{
		i = 0;
		while (pars->file[pars->end_args][i])
		{
			if (ft_iswhitespace(pars->file[pars->end_args], i) != 0
				&& pars->file[pars->end_args][i] != '\n')
			{
				check++;
				break ;
			}
			i++;
		}
		if (!check)
			pars->end_args++;
	}
	ft_clean_end_map(pars);
	return (0);
}

int	ft_check_side(t_parsing *pars, int i, int j)
{
	int	len;
	int	len1;
	int	len2;

	len = cub3d_strlen(pars->map[j]);
	if (j == pars->map_height - 1 || j == 0)
		return (1);
	if (i == len - 1 || i == 0)
		return (1);
	if (j > 0)
	{
		len1 = cub3d_strlen(pars->map[j - 1]);
		if (i >= len1)
			return (1);
	}
	if (j < pars->map_height)
	{
		len2 = cub3d_strlen(pars->map[j + 1]);
		if (i >= len2)
			return (1);
	}
	return (0);
}
