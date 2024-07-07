/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:13:15 by fvastena          #+#    #+#             */
/*   Updated: 2024/07/05 11:34:03 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem_ptr;

	mem_ptr = malloc(count * size);
	if (!mem_ptr)
		return (NULL);
	ft_bzero(mem_ptr, count * size);
	return (mem_ptr);
}
