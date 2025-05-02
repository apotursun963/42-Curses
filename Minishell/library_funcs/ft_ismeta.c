/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismeta.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:52:29 by atursun           #+#    #+#             */
/*   Updated: 2025/04/02 14:52:29 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_ismeta(char *str, int i)
{
	int		j;
	char	*metachars;

	j = 0;
	metachars = "<|>";
	if (!str || i < 0)
		return (false);
	while (metachars[j] && str[i])
	{
		if (str[i] && str[i] == metachars[j])
			return (true);
		j++;
	}
	return (false);
}
