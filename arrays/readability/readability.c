#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main()
{

    string text = get_string("Text: ");
    int n = strlen(text);
    int phrases = 0;
    for (int i = 0; i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            phrases = phrases + 1;
        }
    }
    // printf("Pharases %i\n", phrases);
    int words = 1;
    for (int i = 0; i < n; i++)
    {
        if (text[i] == ' ')
        {
            words = words + 1;
        }
    }
    int chars = 0;
    for (int i = 0; i < n; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            chars = chars + 1;
        }
    }
    // printf("Chars %i\n", chars);
    // printf("Words %i\n", words);
    float L = (float) (chars * 100) / words;
    // printf("media letras %f\n", L);
    float S = (float) (phrases * 100) / words;
    // printf("media sentenças %f\n", S);
    float index = 0.0588 * L - 0.296 * S - 15.8;

    int grade = round(index);
    if (grade > 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    if (grade < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    printf("Grade %i\n", grade);
    return 0;
}
