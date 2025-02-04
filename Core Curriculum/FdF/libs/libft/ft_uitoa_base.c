/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:28:31 by atursun           #+#    #+#             */
/*   Updated: 2025/02/04 13:28:33 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*	The uitoa_base() converts an unsigned integer into a string, passing it to 
*	the base given as an argument.
*	PARAMETERS
*	#1. The unsigned long to convert.
*	#2. The base in which to convert the number to.
*	RETURN VALUES
*	The string representing the converted number.  
*/

#include "libft.h"

// recursively count long size
static size_t	ft_countsize(unsigned long n, size_t len_base)
{
	if ((n / len_base) == 0)
		return (1);
	else
		return (1 + ft_countsize(n / len_base, len_base));
}

// recursively convert long to string
static void	ft_convbase(unsigned long nbr, char *num, char *base, size_t i)
{
	size_t	len_base;

	len_base = ft_strlen(base);
	if (nbr >= (unsigned long int)len_base)
		ft_convbase((nbr / len_base), num, base, (i - 1));
	num[i] = base[nbr % len_base];
}

char	*ft_uitoa_base(unsigned long nbr, char *base)
{
	size_t		len_nbr;
	size_t		len_base;
	char		*number;

	len_base = ft_strlen(base);
	len_nbr = ft_countsize(nbr, len_base);
	number = malloc((len_nbr + 1) * sizeof(char));
	if (!number)
		return (NULL);
	number[len_nbr--] = '\0';
	ft_convbase(nbr, number, base, len_nbr);
	return (number);
}

