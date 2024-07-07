/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toadzima <toadzima@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:04:16 by toadzima          #+#    #+#             */
/*   Updated: 2024/07/05 14:54:49 by toadzima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_errors(t_cubd *datas, char *err_msg, char *opt)
{
	if (opt)
		printf("%s : %s\n", err_msg, opt);
	else
		printf("%s\n", err_msg);
	if (datas)
		free_all(datas);
	exit(EXIT_FAILURE);
}
