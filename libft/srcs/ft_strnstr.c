/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:17:29 by fvastena          #+#    #+#             */
/*   Updated: 2022/10/31 16:33:26 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len2;
	size_t	i;
	size_t	j;
	char	*hay;

	len2 = ft_strlen(little);
	if (len2 == 0)
		return ((char *)big);
	hay = (char *)big;
	i = 0;
	while (hay[i] != '\0' && i <= len)
	{
		j = 0;
		while (hay[i] && little[j] && big[i + j] == little[j] && i + j < len)
			j++;
		if (j == len2)
			return (hay + i);
		i++;
	}
	return (NULL);
}
