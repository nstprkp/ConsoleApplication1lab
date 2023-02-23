#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int input_check_opt();
int input_check_del(int n);
int check_type(char ch, char str[]);
void add_person(struct people* person, int n, int t);
void made(struct people* person, int n, char c, int t, char const_find[]);
void find_inf(struct people* person, char ch, int* n);
void output(struct people* person, int n);
int comp_by_name(const void* typ1, const void* typ2);
int comp_by_money(const void* typ1, const void* typ2);
int comp_by_age(const void* typ1, const void* typ2);
int comp_by_residence(const void* typ1, const void* typ2);
int comp_full(const void* typ1, const void* typ2);
void delite_elem(struct people* mas, int n);
void menu();
void work_prog(struct people* person, int n);