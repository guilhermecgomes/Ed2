/* Pilha de pointer */

#define Max 20
typedef struct {
        void * apont;
        int item;
}Casa;

typedef struct {
      int topo;
      Casa tabela[Max];
} Pilha;

//protótipos
void criarPilhaVazia(Pilha *);
void *acessarTopo(Pilha *);
int verificarPilhaVazia(Pilha *);
int verificarPilhaCheia(Pilha *);
void pushPilha(Pilha *, void *);
void popPilha(Pilha *);

// implementações
void criarPilhaVazia(Pilha *ap){
     ap->topo = 0;
}
void *acessarTopo(Pilha *ap){
    int k;
    void *t;
    k = ap->topo - 1;
    t = ap->tabela[k].apont;
    return t;
}     
int verificarPilhaVazia(Pilha *ap){
     int vazia;
     if (ap->topo == 0) vazia = 1; else vazia = 0;
     return vazia;
}
int verificarPilhaCheia(Pilha *ap){
     int cheia;
     if (ap->topo == Max) cheia = 1; else cheia = 0;
     return cheia;
}
void pushPilha(Pilha *a, void *novo){
     int k;
     k = a->topo;
     a->tabela[k].item = 0;
     a->tabela[k].apont = novo;
     a->topo = k + 1;
}
void popPilha(Pilha *a){
     int k;
     k = a->topo;
     a->topo = k-1;
}

