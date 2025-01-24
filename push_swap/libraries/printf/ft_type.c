/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:13:10 by atursun           #+#    #+#             */
/*   Updated: 2024/11/04 12:33:43 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(char format, va_list args)
{
	if (format == 'c')
		return (ft_write_chr(va_arg(args, int)));
	else if (format == 's')
		return (ft_write_str(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_write_nbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_write_nbr_u(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_write_hexa(va_arg(args, unsigned int), format));
	else if (format == 'p')
		return (ft_write_ptr((unsigned long)va_arg(args, void *)));
	return (ft_write_chr(format));
}
