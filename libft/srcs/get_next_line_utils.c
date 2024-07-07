/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:50:34 by fvastena          #+#    #+#             */
/*   Updated: 2022/11/14 10:34:16 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_get_index(char *str, int c)
{
	size_t	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_get_save(char *save, char *line, size_t start)
{
	size_t	i;

	i = 0;
	while (line[start])
	{
		save[i] = line[start];
		i++;
		start++;
	}
	save[i] = '\0';
}

char	*ft_get_ret_line(char *line, size_t nl_index)
{
	size_t	i;
	char	*new_line;

	if (line[nl_index] && line[nl_index] == '\n')
		nl_index++;
	new_line = malloc(sizeof(char) * (nl_index + 1));
	if (!new_line)
		return (ft_free_str_return(line));
	i = 0;
	while (i < nl_index)
	{
		new_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		new_line[i] = '\n';
	new_line[i] = '\0';
	free(line);
	return (new_line);
}
