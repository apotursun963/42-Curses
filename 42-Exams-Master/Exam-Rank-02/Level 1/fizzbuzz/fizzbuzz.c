#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void ft_write_number(int number) {
    char str[10] = "0123456789";

    if (number > 9)
        ft_write_number(number / 10);
    write(1, &str[number % 10], 1);
}

void fizzbuzz(int start, int end) {
    for (int i = start; i <= end; i++) {
        if (i % 15 == 0)
            write(1, "fizzbuzz", 8);
        else if (i % 3 == 0)
            write(1, "fizz", 4);
        else if (i % 5 == 0)
            write(1, "buzz", 4);
        else
            ft_write_number(i);
        write(1, "\n", 1);
    }
}

int main() {
    int start, end;

    printf("Enter the start and end numbers (space-separated): ");
    scanf("%d %d", &start, &end);

    fizzbuzz(start, end);

    return 0;
}