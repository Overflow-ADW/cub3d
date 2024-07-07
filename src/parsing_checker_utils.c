/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checker_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:57:29 by toadzima          #+#    #+#             */
/*   Updated: 2024/07/07 19:43:30 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_all_args(t_parsing *pars, int i)
{
	while (i < 6)
	{
		if (pars->is_valid[i] == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_format(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	if (i > 2)
		if (str[i--] == 'b')
			if (str[i--] == 'u')
				if (str[i--] == 'c')
					if (str[i--] == '.')
						return (0);
	return (1);
}

int	ft_iswhitespace(char *str, int i)
{
	if (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		return (0);
	if (str[i] == '\0')
		return (-1);
	return (1);
}

int	ft_check_map(t_parsing *pars)
{
	int	i;
	int	j;
	int	check;

	check = 0;
	j = pars->end_args - 1;
	while (++j < pars->height)
	{
		i = -1;
		pars->line_len = cub3d_strlen(pars->file[j]);
		if (pars->real_width < pars->line_len)
			pars->real_width = pars->line_len;
		printf("line_len during check_map = %d\n", pars->line_len);
		while (++i < (int)pars->line_len)
		{
			if (ft_check_map_char(pars->file[j][i]) == 3)
				check++;
			else if (ft_check_map_char(pars->file[j][i]) == 0)
				return (1);
		}
		if (check > 1)
			return (1);
	}
	if (check == 0)
		return (1);
	return (0);
}

int	ft_copy_map(t_cubd *datas, t_parsing *pars)
{
	int	i;
	int	j;
	int	height;

	height = pars->height - pars->end_args;
	pars->map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!pars->map)
		ft_errors(datas, E_MALLOC, "pars->map");
	pars->map_height = height;
	i = 0;
	j = pars->end_args;
	while (i < height)
	{
		pars->map[i] = ft_strdup(pars->file[j++]);
		if (!pars->map[i])
		{
			free_tabs((void **)pars->map, i);
			ft_errors(datas, E_MALLOC, "pars->map[i]");
		}
		i++;
	}
	pars->map[i] = NULL;
	return (0);
}
