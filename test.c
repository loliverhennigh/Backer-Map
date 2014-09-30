
#include "backer.h"

#include <stdio.h>
#include <time.h>
#include <omp.h>


int main() {
	srand(time(NULL));
	int i= 0;

// all the variables
	int num = 100;
	int size = 100;
	int time_run = 40;

// more
	backer * b = backer_create(size,num);
	int start = 8;
	int order[] = {1, 1, 1, 1, 1, 1, 1, 1};
	backer_init_ordered_a(b,order,start);
	float entropy[time_run];


	for(i = 0; i < time_run; i++)
	{
		backer_iter(b);
//		backer_pert(b, 3);
	}
	backer * r = backer_create_from_other_a(b, order, start);
	
	for(i = 0; i < time_run; i++)
	{
		entropy[i] = backer_entropy_a(r);
		backer_iter(r);
//		backer_pert(b, 4);	
	}

	FILE * fp;
	char *file = "he.txt";
	fp = fopen(file, "w");	

	
	print_array_file(fp, entropy, time_run); 
	
//	printf("lets look at stuff %d \n", point_get_state(r->system_a[1], 500));

	return 0;
}


