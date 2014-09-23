
#include "backer.h"

#include <stdio.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int i= 0;
	backer * b = backer_create(10,10000);
	backer_init_rand(b);
	int start = 4;
	int order[] = {1, 1, 1, 1};
	
	backer_init_rand(b);
//	backer_init_ordered_a(b, order, start);
	backer_create_from_other_a(b, order, start);
	
//	printf("lets look at stuff %d \n", point_get_state(b->system_a[0], 4));

	return 0;
}


