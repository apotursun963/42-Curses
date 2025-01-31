/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:29:33 by atursun           #+#    #+#             */
/*   Updated: 2024/02/10 23:23:07 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*new;
	int		s;
	int		i;
	int		k;

	new = (char *) malloc(sizeof(strs) + 1);
	s = 0;
	k = 0;
	while (s < size)
	{
		i = 0;
		while (strs[s][i] != '\0')
			new[k++] = strs[s][i++];
		i = 0;
		while (sep[i] != '\0' && s != size - 1)
			new[k++] = sep[i++];
		s++;
	}
	new[k] = '\0';
	return (new);
}