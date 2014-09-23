
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
void backer_iter(backer * b);
void backer_pert(backer * b, unsigned int where);

#endif


