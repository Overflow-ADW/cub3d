/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:45:36 by fvastena          #+#    #+#             */
/*   Updated: 2024/07/07 19:01:34 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup(char *path, t_cubd *datas)
{
	int i = 0;
	ft_parsing(path, datas);
	while (datas->pars->file[i])
	{
		printf("%s\n", datas->pars->file[i]);
		i++;
	}
	if (ft_check_map (datas->pars))
		ft_errors (datas, E_MAP_CHAR, NULL);
	ft_copy_map (datas, datas->pars);
	printf("line_len = %d\n", datas->pars->line_len);
	printf("real_width = %d\n", datas->pars->real_width);
	i = 0;
	while (datas->pars->map[i])
	{
		printf("%s\n", datas->pars->map[i]);
		i++;
	}
	if (ft_is_map_closed (datas->pars))
		ft_errors (datas, E_MAP_CLOSED, NULL);
	if (ft_check_all_args(datas->pars, 0))
		ft_errors (datas, E_TX, NULL);
}

int	main(int ac, char **av)
{
	t_cubd	datas;

	if (ac != 2)
		ft_errors(NULL, E_ARGS, NULL);
	if (S_WIDTH > 1920 || S_HEIGHT > 1080)
		ft_errors(NULL, E_RES, NULL);
	init_all(&datas);
	setup(av[1], &datas);
	if (datas.pars->height > 1000 || datas.pars->x > 1000)
		ft_errors(&datas, E_MAP_SIZE, NULL);
	cub3d_game(&datas);
	return (0);
}
