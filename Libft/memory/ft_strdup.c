/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:13:12 by atursun           #+#    #+#             */
/*   Updated: 2024/10/24 10:51:11 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int	size;
	int	index;

	size = ft_strlen(src);
	if (!(str = (char *)malloc(size + 1)))
		return (NULL);
	index = -1;
	while (++index < size)
		str[index] = src[index];
	str[index] = '\0';
	return (str);
}
