/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:37:50 by atursun           #+#    #+#             */
/*   Updated: 2024/10/24 10:51:59 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int	index;
	char	*str;

	if (!(s) || !(str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	index = -1;
	while (s[++index])
		str[index] = f(index, s[index]);
	str[index] = '\0';
	return (str);
}
