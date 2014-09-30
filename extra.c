
#include<stdio.h>

void print_array_file(FILE * fp, float * num, int size)
{
	int i = 0;
	for(i = 0; i < size; i++)
	{
		fprintf(fp, "%f \n", num[i]);
	}
}

