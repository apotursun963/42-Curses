/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:49:46 by atursun           #+#    #+#             */
/*   Updated: 2025/03/02 16:49:46 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

char    *build_path(char *dir, char *cmd, int len)
{
    char *temp;

    temp = malloc(len);
    if (!temp)
        return (NULL);
    ft_strlcpy(temp, dir, len);
    ft_strlcat(temp, "/", len);
    ft_strlcat(temp, cmd, len);
    return (temp);
}

int     execute_cmd(char *path, t_tokens tokens, char **env)
{
    char    *exec_argv[] = {tokens.cmd, tokens.flg, NULL};
    pid_t   pid;

    pid = fork();
    if (pid == -1)
        return (-1);
    if (pid == 0)  // Çocuk proc
    {
        execve(path, exec_argv, env);       // Bir programı çalıştırır, mevcut süreci onunla değiştirir.
        free(path);
        exit(0);
    }
    wait(NULL);     // Alt sürecin bitmesini bekle
    return (1);
}

int    search_cmd_in_path(char *command, char **env)
{
    int     i;
    int     len;
    char    *path;
    char    **dirs;
    int     result;
    char    *temp;
    t_tokens tokens = tokenize(command);

    i = 0;
    path = getenv("PATH");
    dirs = ft_split(path, ':');
    while (dirs[i])
    {   
        len = ft_strlen(dirs[i]) + ft_strlen(tokens.cmd) + 2;
        temp = build_path(dirs[i], tokens.cmd, len);
        if (access(temp, X_OK) == 0)        // Bir dosyanın varlığını ve izinlerini kontrol eder.
        {
            result = execute_cmd(temp, tokens, env);
            return (free(temp), ft_free(dirs), result);
        }
        i++;
    }
    ft_free(dirs);
    return (0);
}

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;

    char *input;
    while (1)
    {
        input = readline(BLUE"atursun"RED"&"GREEN"hakotu"RESET"$ ");
        if (!input)            // burada ise check_signal fonksiyonu kullanarak sinyalleri kontrol etmen gerekiyor
            break ;
        add_history(input);
        if (search_cmd_in_path(input, env) == 0)
            printf("command not found: %s\n", input);
    }
    return 0;
}
