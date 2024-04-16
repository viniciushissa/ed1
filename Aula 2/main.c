#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	
	void *p;
	int i=7;
	float f=23.5;
	
	p = &i;
	printf(" i contem: %d\n",*((int*)p));
	
	p = &f;
	printf(" f contem: %0.2f\n",*((float*)p));
	return 0;
}
