
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
		b->system_a[i] = (point *)malloc(sizeof(point));
		b->system_b[i] = (point *)malloc(sizeof(point));
		point_init(b->system_a[i], size);
		point_init(b->system_b[i], size);
	}
	b->size = size;
	b->num = num;
	b->pos = size/2;
	return b;	
}

backer * backer_create_from_other_a(backer * b, int * order, int start)
{
	int i = 0;
	int j = 0;
	int should = 1;
	int * store = (int *) malloc(sizeof(int) * b->num);

	// make store all one
	for (i = 0; i < b->num; i++)
	{
		store[i] = 1;
	}

	// now test to store them or not
	for (i = 0; i < b->num; i++)
	{
		for (j = 0; j< start; j++)
		{
			if(point_get_state(b->system_a[i], b->pos - start/2 + j) != order[j])
			{
				//printf("order %u \n", point_get_state(b->system_a[i], b->pos - start/2 + j));
				store[i] = 0;
			}
		}
	}

	int sum = 0;
	for (i = 0; i < b->num; i++)
	{
		sum = sum + store[i];
	}
	printf("got some %d", sum);

}

void backer_init_rand(backer * b)
{
	int r = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < b->num; i++)
	{
		for(j = 0; j < b->size; j++)
		{
			r = rand() % 2;
			point_set_state(b->system_a[i], j, r);
			r = rand() % 2;
			point_set_state(b->system_b[i], j, r);
		}
	}
}

void backer_init_ordered_a(backer * b, int * order, int start)
{
	int i = 0;
	int j = 0;
	backer_init_rand(b);
	for (i = 0; i < b->num; i++)
	{
		for (j = 0; j < start; j++)
		{
			point_set_state(b->system_a[i], b->pos - start/2 + j ,order[j]);
		}
	}
}

void backer_init_ordered_b(backer * b, int * order, int start)
{
	int i = 0;
	int j = 0;
	backer_init_rand(b);
	for (i = 0; i < b->num; i++)
	{
		for (j = 0; j < start; j++)
		{
			point_set_state(b->system_b[i], b->pos - start/2 + j ,order[j]);
		}
	}
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
		if (point_get_state(b->system_a[i], where) == point_get_state(b->system_b[i], where))
		{
			point_flip(b->system_a[i], where);
			point_flip(b->system_b[i], where);
		}
	}
}

