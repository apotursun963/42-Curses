/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:48:31 by atursun           #+#    #+#             */
/*   Updated: 2024/02/05 16:59:14 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				lenght;
	unsigned int	index;

	lenght = 0;
	while (dest[lenght] != '\0')
		lenght++;
	index = 0;
	while (src[index] && index < nb)
	{
		dest[lenght] = src[index];
		lenght++;
		index++;
	}
	dest[lenght] = '\0';
	return (dest);
}
