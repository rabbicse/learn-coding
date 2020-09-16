#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
    if(argc != 6)
    {
        fprintf(stderr, "You need to give 5 arguments!\n");
        return 1;
    }

    char line[80];

    FILE *input;
    if(!(input = fopen("spooky.csv", "r"))
    {
        fwrite(strerror, "Cannot open input csv file!");
        return 2;
    }
    
    FILE *output1 = fopen(argv[2], "w");
    FILE *output2 = fopen(argv[4], "w");
    FILE *output3 = fopen(argv[5], "w");

    while(fscanf(input, "%79s[^\n]\n", line) == 1)
    {
        if(strstr(line, argv[1]))
        {
            fprintf(output1, "%s\n", line);
        }
        else if(strstr(line, argv[3]))
        {
            fprintf(output2, "%s\n", line);
        }
        else
        {
            fprintf(output3, "%s\n", line);
        }
    }

    fclose(input);
    fclose(output1);
    fclose(output2);
    fclose(output3);

    return 0;
}