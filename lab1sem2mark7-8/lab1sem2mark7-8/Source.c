#include "Header.h"

typedef enum Gender
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


int input_check()
{
    int val;
    while (scanf_s("%d", &val) != 1 || getchar() != '\n') {
        printf("Wrong! Try again.\n");
        rewind(stdin);
    }
    return val;
}

int input_check_mf()
{
    int val;
    while (scanf_s("%d", &val) != 1 || getchar() != '\n' || (val != 1 && val != 2)) {
        printf("Wrong! Try again.\n");
        rewind(stdin);
    }
    return val;
}

int input_check_del(int n)
{
    int val;
    while (scanf_s("%d", &val) != 1 || getchar() != '\n' || (val<1 && val>n)) {
        printf("Wrong! Try again.\n");
        rewind(stdin);
    }
    return val;
}

void input_struct(struct product* mas, int n)
{
    for (int i = 0; i < n; i++) {
        printf("Enter name: ");
        int m = 1, len = 0;
        char* s = (char*)calloc(m, sizeof(char));
        fflush(stdin);
        char c = getchar();
        if (c == '\n') { c = getchar(); }
        while (c != '\n') {
            s[len++] = c;
            if (len >= m) {
                m *= 2;
                s = (char*)realloc(s, m * sizeof(char));
            }
            c = getchar();
        }
        s[len] = '\0';
        for (int j = 0; j < len; j++) { mas[i].name[j] = s[j]; }

        printf("Enter price: ");
        mas[i].price = input_check();
        printf("Enter quality: ");
        mas[i].kol = input_check();
        printf("If product for male - 1, for female - 2: ");
        int t;
        t = input_check_mf();
        if (t == 1) { mas[i].gend = MALE; }
        else { mas[i].gend = FEMALE; }
        fflush(stdin);
        printf("\n");
    }
}

void output(struct product* mas, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d. name: %s, price: %d, quality: %d, ", i + 1, mas[i].name, mas[i].price, mas[i].kol);
        printf("gender: %s\n\n", mas[i].gend == MALE ? "Male" : "Female");
    }
}

void delte_elem(struct product* mas, int n)
{
    printf("Choose number of struct that you want to delete (1..%d): ", n);
    int nom = input_check_del(n); nom--;
    for (int i = nom; i < n-1; i++) {
        mas[i] = mas[i + 1];
    }
    n--;
    mas = (struct product*)realloc(mas, n * sizeof(struct product));
    output(mas, n);
}

int comp(const void* typ1, const void* typ2)
{
    const struct product* p1 = (const struct product*)typ1;
    const struct product* p2 = (const struct product*)typ2;

    int cmp;
    if (cmp = strcmp(p1->name, p2->name)) return cmp;
    if (cmp = p1->price - p2->price) return cmp;
    if (cmp = p1->kol - p2->kol) return cmp;
    return p1->gend - p2->gend;
}

void sortStruct(struct product* mas, int n)
{
    qsort(mas, n, sizeof(struct product), comp);
    output(mas, n);
}

void menu()
{
    printf("1. Make your struct\n");
    printf("2. Initialize your struct\n");
    printf("3. Display products\n");
    printf("4. Sort products\n");
    printf("5. Delete product\n");
    printf("0. Exit\n");
}

void work_prog()
{
    int n;
    struct product* perfume = (struct product*)calloc(1000, sizeof(struct product));;
    int t = 10, k = 0;
    while (t != 0) {
        fflush(stdin);
        printf("Choose your option: ");
        scanf_s("%d", &t);
        if (t != 1 && k == 0) { printf("Wrong! You should first press 1 button!\n"); }
        if (t == 1 && k != 0) { printf("Wrong! You've already made it.\n"); }
        if (t == 1 && k == 0) {
            printf("Enter the number of products: ");
            n = input_check();
            perfume = (struct product*)realloc(perfume, n * sizeof(struct product));
            k++;
        }
        if (t == 2 && k != 0) { input_struct(perfume, n); }
        if (t == 3 && k != 0) { output(perfume, n); }
        if (t == 4 && k != 0) { sortStruct(perfume, n); }
        if (t == 5 && k != 0) { delte_elem(perfume, n); n--; }
        if (t == 0) { printf("\nThank you! Buy!\n"); }
    }
}
