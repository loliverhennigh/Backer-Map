
#include "point.h"
#include<malloc.h>


void point_init(point * p, unsigned int size)
{
	p->pos = size/2;
	p->list = (int *)malloc(sizeof(int) * size); 
}






