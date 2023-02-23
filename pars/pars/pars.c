#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* ptr;

struct people {
	char* name;
	char* age;
	char* residence;
	char* money;
};

int main(void)
{
	menu();
	int n = 0, nom = 0;
	struct people* person;
	person = (struct people*)calloc(1000, sizeof(struct people));
	char ch;
	if ((ptr = fopen("input.txt", "r")) != NULL) {
		while (!feof(ptr)) {
			ch = fgetc(ptr);
			if (ch == 'm') { find_inf(person, ch, &n); }
		}	
		fclose(ptr);
	}
	else { printf("\nFile not found.\n"); }

	person = (struct people*)realloc(person, n * sizeof(struct people));

	work_prog(person, n);
	return 0; 
}

