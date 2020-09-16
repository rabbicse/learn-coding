#include <stdio.h>
struct preferences
{
    const char *food;
    float exercise_hours;
};
struct fish
{
    const char *name;
    const char *species;
    int teeth;
    int age;
    struct preferences care;
};
typedef struct cell_phone
{
    int cell_no;
    const char *wallpaper;
    float minutes_of_charge;
} phone;

typedef struct bd_cell_phone
{
    const char *prefix;
    phone ph;
} bd_phone;

void update_cell_prefix(bd_phone *bd_ph)
{
    (*bd_ph).prefix = "+880";
    bd_ph->prefix = "+8800";
}
int main()
{
    struct fish snappy = {"Snappy", "Piranga", 69, 4, {"meat", 7.5}};
    printf("Name = %s; food: %s\n", snappy.name, snappy.care.food);

    phone p = {1, "sintra.png", 1.35};
    printf("Phone number: %d\n", p.cell_no);

    bd_phone bp = {"+", {1, "sintra.png", 1.35}};
    bp.ph.cell_no = 2;
    printf("Phone number: %d\n", bp.ph.cell_no);

    update_cell_prefix(&bp);
    printf("Phone prefix: %s\n", bp.prefix);

    return 0;
}