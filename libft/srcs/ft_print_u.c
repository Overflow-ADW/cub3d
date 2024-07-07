/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:08:46 by fvastena          #+#    #+#             */
/*   Updated: 2022/12/05 15:23:01 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_uint(unsigned int n, size_t *count)
{
	char	c;

	if (n >= 10)
		ft_putnbr_uint(n / 10, count);
	c = (n % 10) + 48;
	*count += write(1, &c, 1);
}

void	ft_print_u(va_list args, size_t *count)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	ft_putnbr_uint(n, count);
}
