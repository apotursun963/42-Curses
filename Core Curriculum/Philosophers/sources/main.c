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

Thread'lerin avantajları şunlardır:
- Paralel işlem yapmayı sağlar.
- Aynı bellek alanını paylaştıkları için işlem (Process) oluşturmak kadar maliyetli değildir.
*/

#include "../includes/philo.h"

// thread fonksiyonu
void    print_msg(char *str)
{
    for (int i=1; i <= 5; i++)
    {
        printf("%s - %d\n", str, i);
        usleep(500);
    }
}

int main(int argc, char **argv)
{
    pthread_t   thrd1;
    char *msg = "Yeni Thread";

    pthread_create(&thrd1, NULL, (void *)print_msg, msg);

    // Ana thread devam ediyor
    for (int i = 1; i <= 5; i++)
    {
        printf("Ana Thread - %d\n", i);
        sleep(1);
    }

    // Thread'in bitmesini bekle
    pthread_join(thrd1, NULL);
    
    printf("Thread tamamlandı.\n");
    return 0;
}
