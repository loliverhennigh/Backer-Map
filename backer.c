
#include "backer.h"
#include "point.h"
#include<malloc.h>
#include<math.h>

backer * backer_create(unsigned int size, unsigned int num)
{
	int i = 0;
	backer *b = (backer *)malloc(sizeof(backer));
	b->system_a = (point **)malloc(sizeof(point *) * num);
	b->system_b = (point **)malloc(sizeof(point *) * num);
	b->system_a_store = (point **)malloc(sizeof(point *) * num);
	b->system_b_store = (point **)malloc(sizeof(point *) * num);
	for (i = 0; i < num; i++)
	{
		b->system_a[i] = (point *)malloc(sizeof(point));
		b->system_b[i] = (point *)malloc(sizeof(point));
		b->system_a_store[i] = (point *)malloc(sizeof(point));
		b->system_b_store[i] = (point *)malloc(sizeof(point));
		point_init(b->system_a[i], size);
		point_init(b->system_b[i], size);
		point_init(b->system_a_store[i], size);
		point_init(b->system_b_store[i], size);
	}
	b->size = size;
	b->num = num;
	b->pos = size/2;
	return b;	
}

void backer_create_from_other_a(backer * b, backer * r, int * order, int start)
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
//			printf("order %u \n", point_get_state(b->system_a[i], b->pos - start/2 + j));
			if(point_get_state(b->system_a[i], b->pos - start/2 + j) != order[j])
			{
				store[i] = 0;
			}
		}
	}

	int sum = 0;
	for (i = 0; i < b->num; i++)
	{
		sum = sum + store[i];
	}
	//printf("got some %d", sum);

	int w = 0;
	for (i = 0; i < b->num; i++)
	{
		if(store[i] == 1)
		{
			for (j = 0; j < b->size; j++)
			{
				point_set_state(r->system_a[w], j, point_get_state(b->system_a_store[i], j));
				point_set_state(r->system_a_store[w], j, point_get_state(b->system_a_store[i], j));
				point_set_state(r->system_b[w], j, point_get_state(b->system_b_store[i], j));
				point_set_state(r->system_b_store[w], j, point_get_state(b->system_b_store[i], j));
			}
		//	point_set_pos(r->system_a[w],b->size / 2);
		//	point_set_pos(r->system_b[w],b->size / 2);
			w = w + 1;
		}
	} 
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
			point_set_state(b->system_a_store[i], j, r);
			r = rand() % 2;
			point_set_state(b->system_b[i], j, r);
			point_set_state(b->system_b_store[i], j, r);
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
			point_set_state(b->system_a_store[i], b->pos - start/2 + j ,order[j]);
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
			point_set_state(b->system_b_store[i], b->pos - start/2 + j ,order[j]);
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
	b->pos = b->pos - 1;
}

void backer_pert(backer * b, unsigned int where)
{
	int i = 0;
	for(i = 0; i < b->size; i++)
	{
		point_flip(b->system_a[i], where);
		point_flip(b->system_b[i], where);
	}
}

void backer_pert_coupled(backer * b, unsigned int where)
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

float backer_entropy_a(backer * back)
{
	int i = 0;
	int box[16];
	int * point;

	for(i = 0; i < 16; i++)
	{
		box[i] = 0;
	}	

	for(i = 0; i < back->num; i++)
	{
		box[point_get_box(back->system_a[i])]++;
	}
	
	float entropy = 0.0;
	float probability = 0.0;

	// testing the stuff
	for( i = 0; i < 16; i++)
	{
		probability = (float)box[i]/back->num + .000001;
		entropy = entropy + probability * log(probability);
	}
	return entropy;
}


