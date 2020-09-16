#include<stdio.h>

void go_south(int *lat, int *lon)
{
    *lat = *lat - 1;
    *lon = *lon + 1;
}

int main() 
{
    int lat = 32;
    int lon = -64;
    go_south(&lat, &lon);
    printf("Latitude: %d; Longitude: %d!\n", lat, lon);
    return 0;
}