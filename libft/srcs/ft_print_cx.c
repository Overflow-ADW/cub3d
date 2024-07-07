/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:07:32 by fvastena          #+#    #+#             */
/*   Updated: 2022/11/04 15:07:33 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_cx(va_list args, size_t *count)
{
	unsigned long	n;

	n = va_arg(args, unsigned int);
	ft_putnbr_hexa(n, "0123456789ABCDEF", count);
}
