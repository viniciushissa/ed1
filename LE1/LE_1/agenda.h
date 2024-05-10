typedef struct agenda{
char nome[40];
char email[40];
int telefone;
}AGENDA;

void aloca( AGENDA **pAgenda, int *piEntradas );
void consulta( AGENDA *pAgenda, int iEntradas);

void qs_ordena(AGENDA **pAgenda[], int left, int right );
void ordena( AGENDA *pAgenda[], int iEntradas );

void excluir(AGENDA **pAgenda, int *piEntradas);
void pesquisar(AGENDA *pAgenda, int iEntradas);
void alterar(AGENDA *pAgenda, int iEntradas);
