
#include "point.h"
#include<malloc.h>


int main()
{
	unsigned int size = 2;
	point * p;
	p = (point *) malloc (sizeof(point));
	p->pos = size/2;
	
	p->list = (int *)malloc(sizeof(int) * size); 
	return 0;
}



