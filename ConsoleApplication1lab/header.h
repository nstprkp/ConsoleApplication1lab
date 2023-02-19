#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum Gender;
struct product;
int input_check();
int input_check_mf();
void input_struct(struct product *mas, int n);
void output(struct product *mas, int n);
void delte_elem(struct product *mas, int n);
int comp(const void* typ1, const void* typ2);
void sortStruct(struct product *mas, int n);
void menu();
void work_prog();
