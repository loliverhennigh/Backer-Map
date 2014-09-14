



backer * backer_create(unsigned int size_x, unsigned int size_y, unsigned int num)
{
	backer *b = (backer *)malloc(sizeof(backer));
	b->system_a = (point *)malloc(sizeof(point) * num);
	b->system_b = (point *)malloc(sizeof(point) * num);
	b->size = num;
	return b;	
}






