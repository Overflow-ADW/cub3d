/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:08:36 by fvastena          #+#    #+#             */
/*   Updated: 2022/12/05 15:25:58 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_s(va_list args, size_t *count)
{
	char	*str;
	size_t	len_str;

	str = va_arg(args, char *);
	if (str)
	{
		len_str = ft_strlen(str);
		*count += write(1, str, len_str);
	}
	else
		*count += write(1, "(null)", 6);
}
