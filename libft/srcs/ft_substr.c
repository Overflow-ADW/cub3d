/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:18:17 by fvastena          #+#    #+#             */
/*   Updated: 2022/10/31 17:38:15 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	char	*substr;
	size_t	len_s;
	size_t	i;

	if (!s)
		return (NULL);
	tmp = (char *)s;
	len_s = ft_strlen(tmp);
	if (start > len_s)
		len = 0;
	else if (len > len_s - start)
		len = len_s - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && start + i < len_s && tmp[start + i])
	{
		substr[i] = tmp[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
