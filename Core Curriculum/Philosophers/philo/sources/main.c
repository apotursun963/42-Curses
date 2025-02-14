/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:44:04 by atursun           #+#    #+#             */
/*   Updated: 2025/02/13 12:44:04 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Thread (iş parçacığı), bir programın içinde bağımsız olarak çalışabilen en küçük yürütme birimidir. 
Bir işlem (process) içinde birden fazla thread olabilir ve bu thread'ler aynı bellek alanını paylaşarak çalışır.

thread ve mutex, bir işlemi birden fazla parçaya ayırma ve bu parçaları aynı anda çalıştırma işlemine denir. 
Thread, bir işlemi birden fazla parçaya ayırır ve bu parçaları aynı anda çalıştırır, böylece işlem daha hızlı tamamlanır. 
Mutex ise, bir işlem sırasında kullanılan kaynakların diğer işlemler tarafından kullanılmamasını sağlar. 
Böylece, bir işlem sırasında bir kaynağın birden fazla işlem tarafından aynı anda kullanılması ve bu kaynakta oluşabilecek 
çakışmaların önüne geçilir.

Thread'lerin avantajları şunlardır:
- Paralel işlem yapmayı sağlar.
- Aynı bellek alanını paylaştıkları için işlem (Process) oluşturmak kadar maliyetli değildir.
*/



#include "../includes/philo.h"

// // thread fonksiyonu
// void    print_msg(char *str)
// {
//     for (int i=1; i <= 5; i++)
//     {
//         printf("%s - %d\n", str, i);
//         sleep(500);
//     }
// }

// int main(int argc, char **argv)
// {
//     pthread_t   thrd1;
//     char *msg = "Yeni Thread";

//     pthread_create(&thrd1, NULL, (void *)print_msg, msg);

//     // Ana thread devam ediyor
//     for (int i = 1; i <= 5; i++)
//     {
//         printf("Ana Thread - %d\n", i);
//         sleep(1);
//     }

//     // Thread'in bitmesini bekle
//     pthread_join(thrd1, NULL);
    
//     printf("Thread tamamlandı.\n");
//     return 0;
// }



int inspect_args(int argc, char **argv)
{
    int i;

    if (argc != 5 && argc != 6)
        return (-1);
    i = 1;
    while (i < argc)
    {
        if (ft_atoi(argv[i]) < 0)
            return (-1);
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    if (inspect_args(argc, argv) == -1)
        return (0);
}
