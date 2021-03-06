

#ifndef backer_H
#define backer_H
#include "point.h"
//#include <stdbool.h>
typedef struct {
point ** system_a;
point ** system_b;
point ** system_a_store;
point ** system_b_store;
unsigned int num;
unsigned int size;
unsigned int pos;
} backer;
backer * backer_create(unsigned int size, unsigned int number_points);
void backer_create_from_other_a(backer * b, backer * r, int * order, int start);
void backer_iter(backer * b);
void backer_pert(backer * b, unsigned int where);
void backer_pert_coupled(backer * b);
void backer_init_rand(backer * b);
void backer_init_ordered_a(backer * b, int * order, int start);
void backer_init_ordered_b(backer * b, int * order, int start);
float backer_entropy_a(backer * b);
float backer_entropy_b(backer * b);
int backer_box_sum(backer * b, int * order, int start);
#endif


