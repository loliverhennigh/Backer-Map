

#ifndef _point_H_
#define _point_H_


typedef struct {
	unsigned int pos;
	int * list;

} point;

void point_init(point * p, unsigned int pos);
void point_iter(point * p);
void point_flip(point * p, unsigned int where);
void point_set_state(point * p, unsigned int where, int value);
int point_get_state(point * p, unsigned int where);
void point_print_txt(point * p, int which);

#endif	



