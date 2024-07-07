/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:17:14 by fvastena          #+#    #+#             */
/*   Updated: 2022/10/24 14:40:39 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	char	*new;
	size_t	s_len;
	size_t	i;

	if (!s || !f)
		return (NULL);
	tmp = (char *)s;
	s_len = ft_strlen(tmp);
	new = malloc(sizeof(char) * (s_len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		new[i] = f(i, tmp[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
