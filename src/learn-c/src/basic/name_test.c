#include <stdio.h>

int main()
{
    char first_name[5];
    char last_name[5];
    printf("Enter Last name and First Name: ");
    scanf("%s %s", first_name, last_name);
    printf("First name: %s; Last name: %s", first_name, last_name);

    char food[5];
    printf("Enter favorite food: ");
    fgets(food, sizeof(food), stdin);

    return 0;
}