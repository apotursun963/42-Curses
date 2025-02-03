/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:28:06 by atursun           #+#    #+#             */
/*   Updated: 2025/02/03 14:36:19 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fdf.h"
#include <stdio.h>

int	is_valid_filename(char *file)
{
	char    *res;
	
	res = ft_strrchr(file, '.');
	if (ft_strncmp(res, ".fdf", 4))
		return (0);
	return (1);
}
