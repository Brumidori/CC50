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
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int n = strlen(argv[1]);
    for (int i = 0; i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int k = atoi(argv[1]);
    if (k < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (k > 26)
    {
        k = k % 26;
    }
    string text = get_string("plaintext: ");
    string cipher = text;
    int m = strlen(text);
    for (int i = 0; i < m; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            if ((text[i] + k) > 'z')
            {
                //pega a diferença da key ate a ultima letra 'z'
                int q = 'z' - text[i];
                //soma a key com a primeira letra, retirando o que ja foi andado -1 para considerar o 'a'
                cipher[i] = 'a' + k - q - 1;
            }
            else
            {
                cipher[i] = text[i] + k;
            }
        }

        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            if ((text[i] + k) > 'Z')
            {
                int q = 'Z' - text[i];
                cipher[i] = 'A' + k - q - 1;
            }
            else
            {
                cipher[i] = text[i] + k;
            }
        }
    }
    printf("ciphertext: %s\n", cipher);
    return 0;
}
