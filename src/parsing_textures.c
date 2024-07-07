/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toadzima <toadzima@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:38:59 by toadzima          #+#    #+#             */
/*   Updated: 2024/07/05 15:26:06 by toadzima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_store_texture(t_cubd *datas, int j, int i, int nbr)
{
	int	len;

	while (ft_iswhitespace(datas->pars->file[j], i) == 0
		&& i < datas->pars->line_len)
		i++;
	datas->pars->textures[nbr] = ft_strdup(datas->pars->file[j] + i);
	if (!datas->pars->textures[nbr])
		ft_errors(datas, E_MALLOC, NULL);
	len = cub3d_strlen(datas->pars->textures[nbr]) - 2;
	while (len > 0 && ft_iswhitespace(datas->pars->textures[nbr], len) == 0)
		datas->pars->textures[nbr][len--] = '\0';
	len = ft_strlen(datas->pars->textures[nbr]);
	if (datas->pars->textures[nbr][len - 1] == '\n')
		datas->pars->textures[nbr][len - 1] = '\0';
	return (0);
}

int	ft_check_path(t_cubd *datas, int j, int i)
{
	int	check;
	int	k;

	check = 0;
	if (ft_iswhitespace(datas->pars->file[j], i) != 0)
		ft_errors(datas, E_TEX, NULL);
	while (i < datas->pars->line_len - 1)
	{
		if (ft_iswhitespace(datas->pars->file[j], i) != 0)
			check++;
		if (check != 0 && ft_iswhitespace(datas->pars->file[j], i) == 0)
		{
			k = i;
			while (ft_iswhitespace(datas->pars->file[j], k) == 0
				&& k < datas->pars->line_len)
				k++;
			if (k < datas->pars->line_len - 1)
				ft_errors(datas, E_PATH_ARG, NULL);
		}
		i++;
	}
	if (check != 0)
		return (0);
	ft_errors(datas, E_PATH, NULL);
	return (1);
}

int	ft_check_int_rgb(char *tab)
{
	if (tab[0] > 50 && tab[0] < 58)
		return (1);
	if (tab[0] == 50)
	{
		if (tab[1] > 53 && tab[1] < 58)
			return (1);
		if (tab[1] == 53)
			if (tab[2] > 53 && tab[2] < 58)
				return (1);
	}
	return (0);
}

int	ft_check_rgb_num(t_cubd *datas, int j)
{
	int		i;
	int		count;
	int		size;
	char	tab[3];

	count = 0;
	size = 0;
	i = -1;
	while (++i < datas->pars->line_len)
	{
		if (ft_is_num(datas->pars->file[j][i]) == 0)
			tab[size++] = datas->pars->file[j][i];
		if (datas->pars->file[j][i] == ',')
		{
			size = 0;
			tab[2] = 0;
			count++;
			ft_check_rgb_arg(datas, j, i);
		}
		if (size > 3 || (size == 3 && ft_check_int_rgb(tab)))
			ft_errors(datas, E_RGB, NULL);
	}
	if (count != 2)
		ft_errors(datas, E_RGB, NULL);
	return (0);
}

int	ft_is_valid(int nbr, t_cubd *datas, int j, int i)
{
	if (ft_iswhitespace(datas->pars->file[j], i + 1) != 0)
		return (1);
	if (datas->pars->is_valid[nbr] == 1)
		ft_errors(datas, E_DUP, NULL);
	datas->pars->is_valid[nbr] = 1;
	if (nbr < 4)
		if (ft_check_path(datas, j, i + 1))
			return (1);
	if (ft_store_texture(datas, j, i + 1, nbr))
		return (1);
	return (0);
}
