#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    printf("text: ");
    char *text; 
    scanf("%s", text); 


    float letters = 0, words = 1, sentences = 0;
    for (int x = 0, c = strlen(&text); x < c; x++) // loop to get number of letters, words and sentences
    {
        if (isalpha(&text[x])) // getting number of letters
        {
            letters++;
        }
        if (isblank(&text[x])) // getting number of words
        {
            words++;
        }
        if (&text[x] == '.' || &text[x] == '!' || &text[x] == '?') // getting number of sentences
        {
            sentences++;
        }
    }
    float L = ((letters / words) * 100);
    float S = ((sentences / words) * 100);
    float index = ((0.0588 * L) - (0.296 * S) - 15.8); // formula to get grade level
    int a = round(index);
    if (a >= 1 && a <= 16)
    {
        printf("Grade %d\n", a);
    }
    if (a < 1)
    {
        printf("Before Grade 1\n");
    }
    if (a > 16)
    {
        printf("Grade 16+\n");
    }
}