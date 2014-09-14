
#ifndef backer_H
#define backer_H

#include "point.h"
//#include <stdbool.h>

typedef struct {
	point ** system_a;
	point ** system_b;
	unsigned int size;
} backer;

backer * backer_create(unsigned int size, unsigned int number_points);
void run_inter(backer * b);
void run_pert(backer * b);

#endif


