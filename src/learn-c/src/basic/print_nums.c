#include<stdio.h>

int main()
{
    int nums[] = {1,2,3};
    printf("nums is at %p\n", nums);
    printf("nums + 1 is at %p\n", nums + 1);

    int doses[] = {1, 3, 2, 1000};
    printf("Issue dose %i\n", doses[3]);
    printf("Issue dose %i\n", 3[doses]);
    printf("Issue dose %i\n", *(doses + 3));
    printf("Issue dose %i\n", *(3+ doses));

    return 0;
}