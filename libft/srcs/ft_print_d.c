/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:07:50 by fvastena          #+#    #+#             */
/*   Updated: 2022/12/05 15:21:43 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(long n, size_t *count)
{
	char	c;

	if (n < 0)
	{
		*count += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10, count);
	c = (n % 10) + 48;
	*count += write(1, &c, 1);
}

void	ft_print_d(va_list args, size_t *count)
{
	long	n;

	n = va_arg(args, int);
	ft_putnbr(n, count);
}
