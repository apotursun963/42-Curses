/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:16:53 by atursun           #+#    #+#             */
/*   Updated: 2024/11/12 19:53:55 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

int	len_of_str(char *str);
char	*get_next_line(int fd);
char	*pull_line(char *leftover);
char	*pull_left(char *leftover);
char	*search_new_line(char *str);
char	*read_file(int fd, char *leftover);
char	*merge_str(char *leftover, char *buffer);

#endif
