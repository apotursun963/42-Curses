/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:14:01 by atursun           #+#    #+#             */
/*   Updated: 2024/02/06 20:59:06 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	sign;
	int	num;
	int	index;

	sign = 1;
	num = 0;
	index = 0;
	while ((str[index] == ' ') || (str[index] == '\t')
		|| (str[index] == '\n') || (str[index] == '\v')
		|| (str[index] == '\f') || (str[index] == '\r'))
		index++;
	while ((str[index] == '-') || (str[index] == '+'))
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		num = (num * 10) + (str[index] - '0');
		index++;
	}
	return (num * sign);
}
