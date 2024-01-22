#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Uso: ./ chave de substituição\n");
        return 1;
    }
    int n = strlen(argv[1]);
    string key = argv[1];
    for (int i = 0; i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Deve conter apenas caracteres\n");
            return 1;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("A chave não pode ter caracteres repetidos\n");
                return 1;
            }
        }
        key[i] = toupper(key[i]);
    }
    if (n != 26)
    {
        printf("A chave deve conter 26 caracteres.\n");
        return 1;
    }
    string plaintext = get_string("plaintext: ");
    string ciphertext = plaintext;
    int m = strlen(plaintext);
    for (int i = 0; i < m; i++)
    {
        int j = (int) plaintext[i];

        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            // a key foi convertida para toupper entao soma 32 na tabela ASC
            ciphertext[i] = key[j - 97];
            ciphertext[i] = ciphertext[i] + 32;
        }
        else
        {
            if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            {
                ciphertext[i] = key[j - 65];
            }
        }
    }

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}
