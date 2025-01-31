/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 10:08:36 by atursun           #+#    #+#             */
/*   Updated: 2024/02/10 15:26:00 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*str;
	int		size;
	int		index;

	size = 0;
	while (src[size] != '\0')
		size++;
	str = (char *)malloc(size +1);
	index = 0;
	while (index < size)
	{
		str[index] = src[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}
