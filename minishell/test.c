#include <stdbool.h>
#include <string.h>
#include <stdio.h>


bool is_valid_quote(char *input)
{
    int i = 0;
    char quote = 0;
    int len = strlen(input);
    int quote_count = 0;    // Tırnak sayısını sayar
    bool has_content = false; // İçerik var mı kontrolü

    // Başındaki boşlukları atla
    while (input[i] && input[i] == ' ')
        i++;

    // Input tamamen boşsa yanlış
    if (!input[i])
        return false;

    // Tırnak kontrolü ve içerik belirleme
    while (input[i])
    {
        // Tırnak başlangıcı
        if ((input[i] == '"' || input[i] == '\'') && quote_count == 0)
        {
            quote = input[i];
            quote_count++;
            i++;
        }
        // Tırnak kapanışı
        else if (input[i] == quote && quote_count == 1)
        {
            quote_count++;
            i++;
        }
        // Tırnak içindeyken veya tırnaksızken içerik varsa
        else if (input[i] != ' ' || (quote_count == 1 && input[i] == ' '))
        {
            has_content = true;
            i++;
        }
        // Tırnak içindeyken başka bir tırnak başlarsa hata
        else if ((input[i] == '"' || input[i] == '\'') && quote_count == 1)
            return false;
        else
            i++;
    }

    // Tırnaklar düzgün kapanmadıysa yanlış
    if (quote_count == 1)
        return false;

    // Tırnak varsa ve içerik yoksa yanlış (örneğin, "")
    if (quote_count == 2 && !has_content)
        return false;

    // Tırnaksızsa ve içerik varsa doğru (örneğin, "ls 42-Curses")
    if (quote_count == 0 && has_content)
        return true;

    // Tırnak varsa ve içerik varsa doğru (örneğin, "ls")
    if (quote_count == 2 && has_content)
        return true;

    // Diğer durumlar yanlış
    return false;
}

// Test için main fonksiyonu
int main(void)
{
    char *test_cases[] = {
        "ls 42-Curses", // Doğru (tırnaksız, boşluklu)
        "ls",           // Doğru (tırnaksız, tek kelime)
        "\"ls\"",       // Doğru (tırnaklı, tek kelime)
        "'ls'",         // Doğru (tırnaklı, tek kelime)
        "\"ls 42-Curses\"", // Doğru (tırnaklı, boşluklu)
        "\"\"",         // Yanlış (boş tırnak)
        "\"ls",         // Yanlış (kapanmamış tırnak)
        "ls\"",         // Yanlış (açılmamış tırnak)
        "\"ls'",        // Yanlış (karışık tırnak)
        "",             // Yanlış (tamamen boş)
        "  ls  ",       // Doğru (baştaki ve sondaki boşluklar kabul edilir)
        NULL            // Test sonu
    };

    for (int i = 0; test_cases[i] != NULL; i++)
    {
        printf("Input: %-20s -> %s\n", test_cases[i], is_valid_command(test_cases[i]) ? "Doğru" : "Yanlış");
    }

    return 0;
}