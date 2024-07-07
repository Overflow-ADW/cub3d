/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_adapted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:45:31 by fvastena          #+#    #+#             */
/*   Updated: 2024/07/05 12:45:32 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	cub3d_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*cub3d_strdup(char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

char	*cub3d_strtrim(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new_str)
		return (NULL);
	while (isspace(str[i]))
		i++;
	while (str[i])
	{
		new_str[j] = str[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	i = ft_strlen(new_str) - 1;
	while (new_str[i] == ' ' || new_str[i] == '\t' || new_str[i] == '\n')
	{
		new_str[i] = '\0';
		i--;
	}
	return (new_str);
}

char	*cub3d_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s3;

	s3 = malloc(sizeof(char) * (cub3d_strlen(s1) + cub3d_strlen(s2) + 1));
	if (!s3)
		return (ft_free(s1), NULL);
	j = -1;
	i = -1;
	if (s1)
		while (s1[++i])
			s3[i] = s1[i];
	ft_free(s1);
	if (s2)
		while (s2[++j])
			s3[i++] = s2[j];
	s3[i] = '\0';
	return (s3);
}
