/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:38:05 by fdisci            #+#    #+#             */
/*   Updated: 2024/11/03 16:20:04 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_error(int x, int y)
{
	if (x < 0 || y < 0)
	{
		write(1, "Enter a positive number", 24);
		return ;
	}
}

void	ft_line(int x, int a, int b, int c)
{
	int	i;

	i = 0;
	if (x >= 1)
		ft_putchar(a);
	while (i++ < (x - 2))
		ft_putchar(b);
	if (x >= 2)
		ft_putchar(c);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	ft_error(x, y);
	i = 0;
	if (y >= 1 && x >= 1)
		ft_line(x, '/', '*', '\\');
	while (i++ < y - 2 && x >= 1)
		ft_line(x, '*', ' ', '*');
	if (y >= 2 && x >= 1)
		ft_line(x, '\\', '*', '/');
}
