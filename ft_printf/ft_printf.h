/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:07:39 by atursun           #+#    #+#             */
/*   Updated: 2024/11/04 12:32:39 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_type(char format, va_list args);

int	ft_write_chr(char chr);
int	ft_write_str(char *str);
int	ft_write_nbr(int num);
int	ft_write_nbr_u(unsigned int num);
int	ft_write_hexa(unsigned int num, char type);
int	ft_write_ptr(unsigned long num);
int	ft_base(unsigned long num);
int	ft_reverse_str(char *str_digit, int len_digit);

#endif
