/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:50:45 by toadzima          #+#    #+#             */
/*   Updated: 2024/07/07 18:58:07 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**add_line_to_pars(t_cubd *datas, char *line, char **file)
{
	char	**new_file;
	int		i;

	new_file = malloc(sizeof(char *) * (datas->pars->height + 1));
	if (!new_file)
		ft_errors(datas, E_MALLOC, "new_file");
	i = -1;
	while (++i < datas->pars->height - 1)
		new_file[i] = file[i];
	new_file[i++] = line;
	new_file[i] = NULL;
	ft_free(file);
	return (new_file);
}

char	**ft_stock_file(char *str, t_cubd *datas, t_parsing *pars)
{
	int		fd;
	char	*line;
	char	**file;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_errors(datas, E_OPEN, str);
	file = NULL;
	line = get_next_line(fd);
	while (line)
	{
		pars->height++;
		file = add_line_to_pars(datas, line, file);
		line = get_next_line(fd);
	}
	pars->x = pars->height;
	close(fd);
	return (file);
}

int	ft_check_rgb(t_cubd *datas, int j, int i)
{
	while (ft_iswhitespace(datas->pars->file[j], i) == 0)
		i++;
	if (datas->pars->file[j][i] == 'C')
		ft_is_valid(4, datas, j, i);
	else if (datas->pars->file[j][i] == 'F')
		ft_is_valid(5, datas, j, i);
	else
		return (1);
	i++;
	if (ft_iswhitespace(datas->pars->file[j], i) != 0)
		ft_errors(datas, E_C_F, NULL);
	i++;
	while (ft_iswhitespace(datas->pars->file[j], i) == 0)
		i++;
	i -= 1;
	while (++i < (datas->pars->line_len - 1))
		if ((ft_is_num(datas->pars->file[j][i]) != 0
			&& ft_iswhitespace(datas->pars->file[j], i) == 1
			&& datas->pars->file[j][i] != ','))
			ft_errors(datas, E_ARG_RGB, NULL);
	if (ft_check_rgb_num(datas, j))
		return (1);
	return (0);
}

int	ft_check_current_line(t_cubd *datas, int j, int i)
{
	if (datas->pars->file[j][i] == 'N' && datas->pars->file[j][i + 1] == 'O')
		return (ft_is_valid(0, datas, j, i + 1));
	else if (datas->pars->file[j][i] == 'S'
		&& datas->pars->file[j][i + 1] == 'O')
		return (ft_is_valid(1, datas, j, i + 1));
	else if (datas->pars->file[j][i] == 'W'
		&& datas->pars->file[j][i + 1] == 'E')
		return (ft_is_valid(2, datas, j, i + 1));
	else if (datas->pars->file[j][i] == 'E'
		&& datas->pars->file[j][i + 1] == 'A')
		return (ft_is_valid(3, datas, j, i + 1));
	else if (!ft_check_rgb(datas, j, i))
		return (0);
	ft_errors(datas, E_ARG, NULL);
	return (1);
}

int	ft_check_file(t_cubd *datas, t_parsing *pars)
{
	int	i;
	int	j;

	j = -1;
	while (++j < pars->height)
	{
		i = 0;
		pars->line_len = cub3d_strlen(pars->file[j]);
		if (!ft_check_all_args(pars, 0))
		{
			pars->end_args = j;
			return (0);
		}
		while (pars->file[j][i] && pars->file[j][i] != '\n')
		{
			while (ft_iswhitespace(pars->file[j], i) == 0)
				i++;
			if (ft_check_current_line(datas, j, i) == 0)
				break ;
			else
				ft_errors(datas, E_MISS_ARG, NULL);
			i++;
		}
	}
	return (0);
}
