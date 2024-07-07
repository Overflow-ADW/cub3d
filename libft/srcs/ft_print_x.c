/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:08:55 by fvastena          #+#    #+#             */
/*   Updated: 2022/12/05 15:23:13 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_x(va_list args, size_t *count)
{
	unsigned long	n;

	n = va_arg(args, unsigned int);
	ft_putnbr_hexa(n, "0123456789abcdef", count);
}
