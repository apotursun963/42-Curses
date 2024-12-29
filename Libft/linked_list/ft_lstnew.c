/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:52:21 by atursun           #+#    #+#             */
/*   Updated: 2024/10/24 10:49:43 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*unit;

	if (!(unit = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	unit->content = content;
	unit->next = NULL;
	return (unit);
}
