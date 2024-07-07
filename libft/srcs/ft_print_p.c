/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:08:21 by fvastena          #+#    #+#             */
/*   Updated: 2022/12/05 15:22:49 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_p(va_list args, size_t *count)
{
	unsigned long	ptr;

	ptr = va_arg(args, unsigned long);
	if (ptr)
	{
		*count += write(1, "0x", 2);
		ft_putnbr_hexa(ptr, "0123456789abcdef", count);
	}
	else
	{
		*count += write(1, "0x0", 3);
	}
}
