/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:59:58 by atursun           #+#    #+#             */
/*   Updated: 2025/03/19 15:02:27 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current_unit;
	int		counter;

	if (!lst)
		return (0);
	counter = 0;
	current_unit = lst;
	while (current_unit)
	{
		current_unit = current_unit->next;
		counter++;
	}
	return (counter);
}
