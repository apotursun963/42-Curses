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
    printf("command not found: %s\n", command);
    return (0);
}

/*
main'de öncelikle parsing() diye bir fonksiyon oluştur daha sonra parsing içinde 
her bir komutu boşluklara göre ayırıp (split) token olarak sakla ve her token'ı ayrı ayrı olarak işle
*/

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    char *input;

    handle_signals();
    while (true)
    {
        input = readline(BLUE"atursun"RED"&"GREEN"hakotu"RESET"$ ");
        if (!input)
            exit(1);
        add_history(input);

        // bunlar yerine parsing ekle daha iyi olur
        // önelikle böyle tek tek yap ve her biri için ayrı işlemler 
        // yap sonrasında olmazsa parsing ile daha güzel yaparsın
        search_cmd_in_path(input, env); 
        // redirections_type(input);
        // pipe(input);
        // builtin(input);
    }
    return 0;
}













/*
main'de öncelikle parsing() diye bir fonksiyon oluştur daha sonra parsing içinde 
her bir komutu boşluklara göre ayırıp (split) token olarak sakla ve her token'ı ayrı ayrı olarak işle
*/

/*
Bu fonksiyonda komutlar, yönlendirmeler, pipe ve built-in durumları kontrtol edilecektir ve ona göre test edilecektir
*/

// int is_builtin(char *cmd)
// {
//     char *builtins = {"cd", "echo", "pwd", "export", "unset", "env", "exit", NULL};
//     int i;

//     while (builtins[i])
//     {
//         if (ft_strncmp(cmd, builtins[i], ft_strlen(builtins[i])) == 0
//             && ft_strlen(cmd) == ft_strlen(builtins[i]))
//             return (i + 1);
//         i++;
//     }
//     return (0);
// }

// void    execute_builtin(char **splitted_input, char **env, int builtin_id)
// {
//     // Diğerlerinede uygula
//     if (builtin_id == 1)
//         ft_cd(splitted_input);
// }


// void    execute_command(char **splitted_input, char **env)
// {
//     pid_t pid;
//     int     i;
//     int     len;
//     char    *path;
//     char    **dirs;
//     char    *temp;
//     t_tokens tokens = tokenize(splitted_input[0]); // Sadece ilk kelimeyi tokenize et
//     char *exec_argv[] = {tokens.cmd, NULL}; // Şimdilik flagsız

//     i = 0;
//     path = getenv("PATH");
//     dirs = ft_split(path, ':');
//     while (dirs[i])
//     {   
//         len = ft_strlen(dirs[i]) + ft_strlen(tokens.cmd) + 2;
//         temp = malloc(len + 1);
//         ft_strlcpy(temp, dirs[i], len);
//         ft_strlcat(temp, "/", len);
//         ft_strlcat(temp, tokens.cmd, len);
//         if (access(temp, X_OK) == 0)
//         {
//             pid = fork();
//             if (pid == -1)
//                 return ;
//             else if (pid == 0)  // Çocuk proc
//             {
//                 execve(path, exec_argv, env);       // Bir programı çalıştırır, mevcut süreci onunla değiştirir.
//                 free(path);
//                 exit(0);
//             }
//             else
//                 waitpid(pid, NULL, 0);
//         }
//         i++;
//     }
//     ft_free(dirs);
// }

// void parsing(char *input, char **env)
// {
//     int i;
//     // int builtin_id;
//     char **splitted_input;
    
//     i = 0;
//     splitted_input = ft_split(input, ' ');
//     // builtin_id = is_builtin(splitted_input[0]);
//     // if (builtin_id)
//     //     execute_builtin(splitted_input, env, builtin_id);
//     while (splitted_input[i])
//     {
//         // if (ft_strncmp(splitted_input[i], "|", 1) == 0)
//         //     parse_pipe(splitted_input);
//         // else if (ft_strncmp(splitted_input[i], "<", 1) == 0
//         //     || ft_strncmp(splitted_input[i], ">", 1) == 0
//         //     || ft_strncmp(splitted_input[i], "<<", 2) == 0
//         //     || ft_strncmp(splitted_input[i], ">>", 2) == 0)
//         //     parse_redirections(splitted_input);
//         if (i == 0)
//             execute_command(splitted_input, env);
//         i++;
//     }
// }

// int main(int argc, char **argv, char **env)
// {
//     (void)argc;
//     (void)argv;
//     char *input;

//     handle_signals();
//     while (1)
//     {
//         input = readline(BLUE"atursun"RED"&"GREEN"hakotu"RESET"$ ");
//         if (!input)
//             exit(1);
//         add_history(input);
//         parsing(input, env);
//     }
// }

