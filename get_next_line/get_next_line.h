/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:23:48 by atursun           #+#    #+#             */
/*   Updated: 2024/11/14 15:23:48 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_len_of_str(char *str);
char	*ft_pull_line(char *leftover);
char	*ft_pull_left(char *leftover);
char	*ft_search_new_line(char *str);
char	*ft_read_file(int fd, char *leftover);
char	*ft_merge_str(char *leftover, char *buffer);

#endif
