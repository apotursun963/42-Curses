/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:11:43 by atursun           #+#    #+#             */
/*   Updated: 2024/02/10 19:25:38 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] && s2[i]) && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_print_parameters(char **argv)
{
	int	index;
	int	index2;

	index = 1;
	while (argv[index])
	{
		index2 = 0;
		while (argv[index][index2])
		{
			write(1, &argv[index][index2], 1);
			index2++;
		}
		write(1, "\n", 1);
		index++;
	}
}

int	main(int argc, char **argv)
{
	char	*temp;
	int		index;
	int		index2;

	index = 1;
	while (index < argc)
	{
		index2 = 1;
		while (index2 < argc)
		{
			if (ft_strcmp(argv[index], argv[index2]) < 0)
			{
				temp = argv[index];
				argv[index] = argv[index2];
				argv[index2] = temp;
			}
			index2++;
		}
		index++;
	}
	ft_print_parameters(argv);
	return (0);
}
