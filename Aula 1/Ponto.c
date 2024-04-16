typedef struct ponto Ponto;

//cria novo ponto
Ponto* PontoCria(float x, float y);
//libera ponto
void Ponto_Libera(Ponto* p);
//acessa valores x e y de um ponto
int Ponto_Acessa(Ponto* p, float* x, float* y);
//atribui valores x e y a um ponto 
int PontoAtribui(Ponto* p, float x, float y);
//calcula distancia entre dois pontos
float PontoDistancia(Ponto* p1, Ponto* p2);

