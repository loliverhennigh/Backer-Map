

#ifndef _point_H_
#define _point_H_


typedef struct {
	unsigned int pos;
	int * list;

} point;

void point_init(point * p, unsigned int pos);
void point_iter(point * p);
void point_flip(point * p, unsigned int where);

#endif	



