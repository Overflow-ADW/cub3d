/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:10:15 by fvastena          #+#    #+#             */
/*   Updated: 2022/12/05 15:24:14 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isconv(const char *format, size_t index)
{
	char	*flags;
	size_t	i;

	if (!format[index])
		return (-1);
	flags = "cspdiuxX%";
	i = 0;
	while (i < 9 && flags[i] != format[index])
		i++;
	if (flags[i])
		return (i);
	return (-1);
}

void	ft_putnbr_hexa(unsigned long n, const char *base, size_t *count)
{
	int	c;

	if (n >= 16)
		ft_putnbr_hexa(n / 16, base, count);
	c = base[n % 16];
	*count += write(1, &c, 1);
}
