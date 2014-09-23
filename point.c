
#include "point.h"
#include<malloc.h>


void point_init(point * p, unsigned int size)
{
	p->pos = size/2;
	p->list = (int *)malloc(sizeof(int) * size); 
}

void point_iter(point * p)
{
	p->pos = p->pos + 1;
}

void point_flip(point * p, unsigned int where)
{
	p->list[p->pos + where] = -p->list[p->pos + where] + 1;
}

int point_get_value(point * p, unsigned int where)
{
	return p->list[p->pos + where];

}

