#include<stdio.h>
#include <string.h>

void reverse(char *input)
{
    size_t len = strlen(input);

    char *t = input + len - 1;
    while (t >= input)
    {
        printf("%c", *t);
        t = t - 1;
    }
    
}

int main()
{
    /* reverse string */
    char input[] = "Hello Everyone";
    reverse(input);

    /* string array */
    char *names_for_dog[] = {"Bowser", "Bonza", "Snodgrass"};
    return 0;
}