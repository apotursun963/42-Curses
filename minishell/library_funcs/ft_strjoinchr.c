/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:06:50 by atursun           #+#    #+#             */
/*   Updated: 2025/03/22 18:06:50 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinchr(char *str, char chr)
{
	char	*new_str;
	int		len;
	int		i;

	len = ft_strlen(str);
	new_str = (char *)malloc(sizeof(char) * (len + 2));
	i = -1;
	while (str[++i])
		new_str[i] = str[i];
	new_str[i] = chr;
	new_str[i + 1] = '\0';
	return (free(str), new_str);
}
