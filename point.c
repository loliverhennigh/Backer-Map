
#include "point.h"
#include<malloc.h>


void point_init(point * p, unsigned int size)
{
	p->pos = size/2;
	p->list = (int *)malloc(sizeof(int) * size); 
}

void point_iter(point * p)
{
	p->pos = p->pos + 1;
}

void point_flip(point * p, unsigned int where)
{
	p->list[p->pos + where] = -p->list[p->pos + where] + 1;
}

int point_get_state(point * p, unsigned int where)
{
	return p->list[where];

}

void point_set_state(point * p, unsigned int where, int state)
{
	p->list[where] = state;
}

void point_set_pos(point * p, unsigned int where)
{
	p->pos = where;
}

int point_get_box(point * p)
{
	int r = 0;
	r = r + point_get_state(p, p->pos - 2);
	r = r + 2*point_get_state(p, p->pos - 1);
	r = r + 4*point_get_state(p, p->pos );
	r = r + 8*point_get_state(p, p->pos +1);
	return r;
}

