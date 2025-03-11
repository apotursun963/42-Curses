/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:08:20 by atursun           #+#    #+#             */
/*   Updated: 2025/03/11 13:08:20 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* Adımlar
1. ilk olarak ortam değişkenlerinin hepsini bir listeye ekle ki liste üzerinden her yerde erişebilesin
2. Shell'i başlat yani, Sinyalleri ve Kullanıcıdan input al.
*/


#include "../includes/minishell.h"


int parse_input(t_shell shell, t_env_lst *envs, char *input)
{
    (void)shell;
    (void)envs;
    char *new_input;

    if (is_only_whitespace(input) == true)
        return (1);
    new_input = trim_whitespace(input);
    if (!new_input)
        exit(1);
    printf("validate_syntax sonucu: %d\n", validate_syntax(new_input));
    if (validate_syntax(new_input) == false)
        return (1);
    printf("giriyorumu\n");
    // if (handling_parse(shell, env, new_input) == false) 
    //     exit(1);   
    return (0);
}

int main(int argc, char **argv, char **env)
{
    char        *input;
    t_shell     shell;
    t_env_lst   *envs;

    (void)argc;
    (void)argv;
    envs = NULL;
    envs = convert_envs_to_list(envs, env);
    while (true)
    {
        handle_signals();
        input = readline(BLUE"atursun"RED"&"GREEN"hakotu"RESET"$ ");
        if (!input)
            exit(1);
        add_history(input);
        parse_input(shell, envs, input);
    }
    return (0);
}
