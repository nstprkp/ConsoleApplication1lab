#include "header.h"

enum Gender
{
    MALE,
    FEMALE
};

struct product
{
    char name[100];
    int price;
    int kol;
    enum Gender gend;

};

int main()
{
    menu();
    work_prog();
    return 0;
}
