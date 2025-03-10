/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:41:21 by atursun           #+#    #+#             */
/*   Updated: 2025/03/10 16:01:02 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

void cd(char *input)
{
    char current_path[1000];
    char new_path[1000];

    // Mevcut dizini al
    getcwd(current_path, sizeof(current_path));
    printf("Mevcut dizin: %s\n", current_path);

    // Eğer input mutlak yolsa (örneğin, /tmp ile başlıyorsa), doğrudan kullan
    if (input[0] == '/') {
        strncpy(new_path, input, sizeof(new_path) - 1);
        new_path[sizeof(new_path) - 1] = '\0'; // Güvenlik için null-terminated
    } else 
    {
        // Göreli yol ise, mevcut dizinle birleştir
        strncpy(new_path, current_path, sizeof(new_path) - 1);
        new_path[sizeof(new_path) - 1] = '\0';
        ft_strlcat(new_path, "/", sizeof(new_path));     // Ayraç ekle
        ft_strlcat(new_path, input, sizeof(new_path));  // input'u ekle
    }
    chdir(new_path);
}
