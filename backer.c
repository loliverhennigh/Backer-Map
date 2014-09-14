
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

void run_inter(backer * b)
{
	


}





