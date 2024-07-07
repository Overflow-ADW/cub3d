/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:30:48 by fvastena          #+#    #+#             */
/*   Updated: 2022/12/05 15:26:05 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list			args;
	size_t			count;
	size_t			i;
	static t_tabf	tab[9] = {ft_print_c, ft_print_s, ft_print_p, ft_print_d,
		ft_print_i, ft_print_u, ft_print_x, ft_print_cx, ft_print_prct};

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && ft_isconv(format, i + 1) != -1)
		{
			tab[ft_isconv(format, i + 1)](args, &count);
			i++;
		}
		else
			count += write(1, format + i, 1);
		i++;
	}
	va_end(args);
	return (count);
}
