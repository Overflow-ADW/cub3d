/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:16:56 by fvastena          #+#    #+#             */
/*   Updated: 2022/10/31 16:41:35 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	i = 0;
	if (size <= destlen)
		return (size + srclen);
	while ((destlen + 1 + i) < size && src[i])
	{
		dest[destlen + i] = ((unsigned char *)src)[i];
		i++;
	}
	dest[destlen + i] = '\0';
	if (size > destlen)
		return (destlen + srclen);
	return (srclen + size);
}
