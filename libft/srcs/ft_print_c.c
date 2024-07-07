/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:07:25 by fvastena          #+#    #+#             */
/*   Updated: 2022/12/05 15:23:20 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_c(va_list args, size_t *count)
{
	unsigned char	c;

	c = (unsigned char)va_arg(args, int);
	*count += write(1, &c, 1);
}
