/* fila de pointer */

typedef struct Celula{
        void * item;         /* item é um pointer */
        struct Celula *next; /* o campo next guarda o endereço do elemento seguinte da fila */
} Celula;                

typedef struct{
        Celula *inicio;      /* inicio tem o endereço do primeiro da fila */
        Celula *fim;         /* fim guarda o endereço do ultimo da fila */
} Fila;


// prototipos das funções 
void criarFilaVazia(Fila *);  /* o construtor cria a fila vazia */

void *acessarFila(Fila *);      /* devolve o primeiro da fila */
int verificarFilaVazia(Fila *);  /* devolve 1 se a fila estiver vazia */

void pushFila(Fila *, void *);   /* coloca o valor dado no fim da fila */
void popFila(Fila *);           /* retira o primeiro da fila */


// implemenetações 
void criarFilaVazia(Fila *fi){
     fi->inicio = NULL;
     fi->fim = NULL;   
}
void *acessarFila(Fila *fi){
    Celula *aux;
    void * valor;
    aux = fi->inicio; 
    if (aux == NULL) valor = NULL;
    else valor = aux->item;
    return valor;
}
int verificarFilaVazia(Fila *fi){
     int vazia;
     Celula *aux;
     aux = fi->inicio; 
     if (aux == NULL) vazia = 1;
     else vazia = 0;
     return vazia;
}
void pushFila(Fila *fi, void *ap){
     Celula *p;
     Celula *aux;
     p = (Celula *)malloc(sizeof(Celula));
     p->item = ap; p->next = NULL;
     if (fi->inicio == NULL) fi->inicio = p;
     else {aux = fi->fim;  aux->next = p;}
     fi->fim = p;   
}
void popFila(Fila *fi){
     Celula *seg;
     Celula *pri;
     pri = fi->inicio; 
     if (fi->inicio != NULL){
        if (fi->inicio == fi->fim) {fi->inicio = NULL; fi->fim = NULL;}
        else {seg = pri->next; fi->inicio = seg;}
        }
}
