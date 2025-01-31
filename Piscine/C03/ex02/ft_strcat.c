/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:53:22 by atursun           #+#    #+#             */
/*   Updated: 2024/02/05 16:55:32 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	lenght;
	int	index;

	lenght = 0;
	while (dest[lenght] != '\0')
		lenght++;
	index = 0;
	while (src[index] != '\0')
	{
		dest[lenght] = src[index];
		lenght++;
		index++;
	}
	dest[lenght] = '\0';
	return (dest);
}
