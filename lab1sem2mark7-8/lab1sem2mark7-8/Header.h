#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int input_check();
int input_check_mf();
int input_check_del(int n);
void input_struct(struct product* mas, int n);
void output(struct product* mas, int n);
void delte_elem(struct product* mas, int n);
int comp(const void* typ1, const void* typ2);
void sortStruct(struct product* mas, int n);
void menu();
void work_prog();