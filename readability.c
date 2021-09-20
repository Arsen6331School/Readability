#include <stdio.h>
#include <string.h>
#include <math.h>

void ask_for_text(char *);
float calculate_index(int, int, int);

const int LEN_INPUT = 1000;

int main()
{
    char in[LEN_INPUT];
    ask_for_text(in);

    int words = 0;
    int letters = 0;
    int sentences = 0;
    for (int i = 0; in[i] != '\0'; i++)
    {
        if ((in[i] >= 'A' && in[i] <= 'Z') || (in[i] >= 'a' && in[i] <= 'z'))
        {
            letters++;
        }
        else if (in[i] == ' ')
        {
            words++;
        }
        else if (in[i] == '.' || in[i] == '!' || in[i] == '?')
        {
            if (in[i + 1] != ' ')
            {
                words++;
            }
            sentences++;
        }
    }
    float index = calculate_index(words, letters, sentences);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(index));
    }
}

void ask_for_text(char input[])
{
  printf("Text: ");
  fgets(input, LEN_INPUT, stdin);
}

float calculate_index(int words, int letters, int sentences)
{
    return (0.0588 * (((float)letters / (float)words)*100.)) - (0.296 * (((float)sentences / (float)words)*100.)) - 15.8;
}