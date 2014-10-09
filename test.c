
#include "backer.h"

#include <stdio.h>
#include <time.h>
#include <omp.h>


void experiment_boundry_a_pert(int num, int size, int time_run, int pert_time);

int main() {
	srand(time(NULL));

// all the variables
	int num = 10000000;
	int size = 100;
	int time_run = 40;
	int pert_time = 2;
	experiment_boundry_a_pert(num, size, time_run, pert_time);
	
/*
// more
	backer * b = backer_create(size,num);
	int start = 8;
	int order[] = {1, 1, 1, 1, 1, 1, 1, 1};
	backer_init_ordered_a(b,order,start);
	float entropy[time_run];

	for(i = 0; i < time_run; i++)
	{
		backer_iter(b);
	}
	
	int sum = backer_box_sum(b, order, start);
	backer * r = backer_create(b->size, sum);
	backer_create_from_other_a(b, r, order, start);


//	point_print_txt(r->system_a[1], size);
//	point_print_txt(r->system_a[2], size);

	for(i = 0; i < time_run; i++)
	{
		backer_iter(r);
//		printf("state %d \n", point_get_state(r->system_a[1], r->pos));
//		printf("state %d \n", point_get_state(r->system_a[2], r->pos));
		entropy[i] = backer_entropy_a(r);
//		backer_pert(b, 4);	
	}

	FILE * fp;
	char *file = "he.txt";
	fp = fopen(file, "w");	
	
	print_array_file(fp, entropy, time_run); 
*/
	return 0;
}


void experiment_boundry_a_pert(int num, int size, int time_run, int pert_time)
{
	int i= 0;
// more
	backer * b = backer_create(size,num);
	int start = 8;
	int order[] = {1, 1, 1, 1, 1, 1, 1, 1};
	backer_init_ordered_a(b,order,start);
	float entropy[time_run];

	for(i = 0; i < time_run; i++)
	{
		backer_iter(b);
	}
	
	int sum = backer_box_sum(b, order, start);
	backer * r = backer_create(b->size, sum);
	backer_create_from_other_a(b, r, order, start);


	for(i = 0; i < time_run; i++)
	{
		backer_iter(r);
		entropy[i] = backer_entropy_a(r);
	}

	FILE * fp;
	char *file = "experiment_boundry_a_no_pert.txt";
	fp = fopen(file, "w");	
	
	print_array_file(fp, entropy, time_run); 

	// now for the pert simulation
	backer * bb  = backer_create(size,num);
	
	backer_init_ordered_a(bb,order,start);


	for(i = 0; i < pert_time; i++)
	{
		backer_iter(bb);
	}
	backer_pert(bb, bb->pos);
	for(i = pert_time; i < time_run; i++)
	{
		backer_iter(bb);
	}

	sum = backer_box_sum(bb, order, start);
	backer * rr = backer_create(bb->size, sum);
	backer_create_from_other_a(bb, rr, order, start);

	for(i = 0; i < pert_time; i++)
	{
		backer_iter(rr);
		entropy[i] = backer_entropy_a(rr);
	}
	backer_pert(rr, rr->pos);
	for(i = pert_time; i < time_run; i++)
	{
		backer_iter(rr);
		entropy[i] = backer_entropy_a(rr);
	}

	FILE * ffp;
	char *ffile = "experiment_boundry_a_yes_pert.txt";
	ffp = fopen(ffile, "w");	
	
	print_array_file(ffp, entropy, time_run); 
}

