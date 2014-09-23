
#include "backer.h"
#include "point.h"
#include<malloc.h>

backer * backer_create(unsigned int size, unsigned int num)
{
	int i = 0;
	backer *b = (backer *)malloc(sizeof(backer));
	b->system_a = (point **)malloc(sizeof(point *) * num);
	b->system_b = (point **)malloc(sizeof(point *) * num);
	for (i = 0; i < num; i++)
	{
		point_init(b->system_a[i], size);
		point_init(b->system_b[i], size);
	}
	b->size = num;
	return b;	
}

void backer_iter(backer * b)
{
	int i = 0;
	for(i = 0; i < b->size; i++)
	{
		point_iter(b->system_a[i]);
		point_iter(b->system_b[i]);
	}
}

void backer_pert(backer * b, unsigned int where)
{
	int i = 0;
	for(i = 0; i < b->size; i++)
	{
		if (point_get_value(b->system_a[i], where) == point_get_value(b->system_b[i], where))
		{
			point_flip(b->system_a[i], where);
			point_flip(b->system_b[i], where);
		}
	}
}

