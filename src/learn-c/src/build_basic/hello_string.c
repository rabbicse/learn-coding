#include <stdio.h>

void fortune_cookie(char msg[])
{
    printf("Message reads: %s\n", msg);
    printf("msg occupies %i bytes\n", sizeof(msg));
}

void skip(char *msg)
{
    puts(msg + 6);
}

int main()
{
    char quote[] = "Cookies make you fat";
    fortune_cookie(quote);

    int contestents[] = {1, 2, 3};
    int *choice = contestents;
    contestents[0] = 2;
    contestents[1] = contestents[2];
    contestents[2] = *choice;
    printf("I'm going to pick contestant number %i\n", contestents[2]);

    char s[] = "How big is it?";
    char *t = s;
    printf("Sizeof S: %i\n", sizeof(s));
    printf("Sizeof T: %i\n", sizeof(t));

    int drinks[] = {4, 2, 3};
    printf("1st order: %i drinks\n", drinks[0]);
    printf("1st order: %i drinks\n", *drinks);

    printf("3rd order: %i drinks\n", drinks[2]);
    printf("3rd order: %i drinks\n", *(drinks + 2));


    char *msg_from_amy = "Don't if call me";
    skip(msg_from_amy);
    return 0;
}