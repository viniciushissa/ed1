#include <stdio.h>
#include <stdlib.h>
#include "Ponto.h"

int main(){
	float d;
	Ponto *p,*q;
	p = PontoCria(10,21);
	q = PontoCria(7,25);
	
	d = PontoDistancia(p,q);
	printf("Distancia entre os pontos : %f\n",d);
	Ponto_Libera(q);
	Ponto_Libera(p);
//	system(pause);
	return 0;
}
