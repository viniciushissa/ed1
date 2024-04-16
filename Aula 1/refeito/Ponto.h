Ponto* PontoCria(float x, float y){
	Ponto* p =(Ponto*)malloc(sizeof(Ponto));
	if(p!= NULL){
		p->x = x;
		p->y = y;
	}
	return p;
}

void Ponto_Libera(Ponto* p){
	free(p);
}

int Ponto_Acessa(Ponto* p, float* x, float* y){
	if(p == NULL)
	return 0;
	*x = p->x;
	*y = p->y;
	return 1;
}

int PontoAtribui(Ponto* p, float x, float y){
	if(p == NULL)
	 return 0;
	 p-> x = x;
	 p-> y = y;
	 return 1;
}

float PontoDistancia(Ponto* p1, Ponto* p2){
	if(p1 == NULL || p2 == NULL)
	return 1;
	float dx = p1->x - p2->x;
	float dy = p1->y - p2->y;
	
	return sqrt(dx*dx+dy*dy); 
}
