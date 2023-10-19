typedef struct No no;

int menu(void);

int menuListaDinamica(void);

void listaDinamica();

char *criarLista(int tamanho);

char *inserir(char *vetor, int tamanho);

void imprimir(char *vetor, int tamanho) ;

// Funções para lista estatica
void listaEstatica(void);

void preencherVetor(int vetor[]);

void printarVetor(int vetor[]);

void mergeSortEstatico(int vetor[], int inicio, int tamanho);
