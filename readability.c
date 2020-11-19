#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char *inputString(FILE* fp, size_t size){
//The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(char)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(char)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(char)*len);
}

int main(void)
{
    char *text;
    printf("text: "); 
    text =  inputString(stdin, 10);

    


    float letters = 0, words = 1, sentences = 0;
    for (int x = 0, c = strlen(text); x < c; x++) // loop to get number of letters, words and sentences
    {
        if (isalpha(text[x])) // getting number of letters
        {
            letters++;
        }
        if (isblank(text[x])) // getting number of words
        {
            words++;
        }
        if (text[x] == '.' || text[x] == '!' || text[x] == '?') // getting number of sentences
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

    free(text);
    return 0;
}