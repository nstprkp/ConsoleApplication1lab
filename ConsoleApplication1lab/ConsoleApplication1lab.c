#include <stdio.h>
#include <stdlib.h>

struct person
{
    int age;
    char name[20];
};

struct phone
{
    int number;
    int size;

};

int main()
{
    struct person people[] = { {23, "Tom"}, {32, "Bob"}, {26, "Alice"}, {41, "Sam"}};
    int n = sizeof(people)/sizeof(people[0]);
    for(int i=0; i<n; i++)
    {
        printf("Name:%s \t Age: %d \n", people[i].name, people[i].age);
    }
    return 0;
}
