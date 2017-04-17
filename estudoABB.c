#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "PilhaPointer.h"
#include "FilaPointer.h"
#include "Booleano.h"

#define MaxNos 13

typedef struct No{
	int chave;
	char satelite;
	struct No* dir;
	struct No* esq;
}No;

typedef struct No* ArvoreBB;

//prototipos TIPO No 

void mostrar(No*);							//[1]
No* criarNo(int, char);						//[2]

ArvoreBB criarArvoreBB();					//[3]
bool verificarArvoreVazia(ArvoreBB);		//[4]
void mostrarArvoreERD(ArvoreBB);			//[5]
void mostrarArvoreRED(ArvoreBB);			//[6]
void mostrarArvoreEDR(ArvoreBB);			//[7]
void mostrarArvoreBFS(ArvoreBB);			//[8]

int buscarNo(ArvoreBB,int);					//[9]
ArvoreBB inserirNo(ArvoreBB,No*);			//[10]
ArvoreBB removerNo(ArvoreBB,int);			//[11]
ArvoreBB removerRaiz(ArvoreBB);				//[12]
int determinarAltura(ArvoreBB);				//[13]
No* obterPai(ArvoreBB, No*);				//[14]
No* obterAncestral(ArvoreBB,No*,No*);		//[15]
No* obterSeguinte(ArvoreBB,No*);			//[16]

//implementação


main(){
	setlocale(LC_ALL, "Portuguese");
    int chaves[MaxNos] = {30, 7, 40, 4, 20, 35, 50, 10, 22, 8, 12, 11,3};
    char satelites[MaxNos] = {'A','B','C','D','E','F','G','H','I','J','K','L','M'};
    ArvoreBB a = criarArvoreBB();
    ArvoreBB b = criarArvoreBB();
    No* no,*p;
    int i;
    for(i = 0; i < MaxNos; i++){
        no = criarNo(chaves[i], satelites[i]);
        a = inserirNo(a, no);	
    }
      
    printf("Arvore:\n\n");printf("Arvore em eRd - Recursivo\n");  		mostrarArvoreERD(a);
    printf("\n\n");		  printf("Arvore em Red - Não recursivo\n");    mostrarArvoreRED(a);
	printf("\n\n");		  printf("Arvore em edR - Não recursivo\n");	mostrarArvoreEDR(a);
	printf("\n\n");		  printf("Arvore em Bfs - Recursivo\n");		mostrarArvoreBFS(a);
	
	no->chave = 12;
	no = obterPai(a,no);
	printf("\n%d\n",no->chave);
	no = obterAncestral(a,no,p);
	printf("\n%d\n",no->chave);
	 
	/*
	a = removerNo(a,30);
	
	printf("Arvore:\n\n");printf("Arvore em eRd - Recursivo\n");  		mostrarArvoreERD(a);
   	printf("\n\n");		  printf("Arvore em Red - Não recursivo\n");    mostrarArvoreRED(a);
	printf("\n\n");		  printf("Arvore em edR - Não recursivo\n");	mostrarArvoreEDR(a);
	printf("\n\n");		  printf("Arvore em Bfs - Recursivo\n");		mostrarArvoreBFS(a);
	
	a = removerNo(a,20);
	
	printf("Arvore:\n\n");printf("Arvore em eRd - Recursivo\n");  		mostrarArvoreERD(a);
   	printf("\n\n");		  printf("Arvore em Red - Não recursivo\n");    mostrarArvoreRED(a);
	printf("\n\n");		  printf("Arvore em edR - Não recursivo\n");	mostrarArvoreEDR(a);
	printf("\n\n");		  printf("Arvore em Bfs - Recursivo\n");		mostrarArvoreBFS(a);
	
	int h;
	h = determinarAltura(a);
	printf("\n%d\n",h);
	*/
}

//implementação TIPO No

void mostrarNo(No *p){							//[1]
	if(p != NULL){
		printf("|%d|%c|-",p->chave,p->satelite);
	}
	else{
		printf("No inexistente");
	}
}

No* criarNo(int c,char ch){						//[2]
	No* aux;
	aux = (struct No*) malloc (sizeof(struct No));
	aux->chave = c;
	aux->satelite = ch;
	aux->dir = NULL;
	aux->esq = NULL;
	return aux;
}

ArvoreBB criarArvoreBB(){						//[3]
	ArvoreBB ap;
	ap = NULL;
	return ap;
}

bool verificarArvoreVazia(ArvoreBB ap){			//[4]
	bool ok;	ok = TRUE;
	if(ap != NULL){
		ok = FALSE;
	}
	return ok;
}

void mostrarArvoreERD(ArvoreBB ap){				//[5]
	if(ap != NULL){
		mostrarArvoreERD(ap->esq);
		mostrarNo(ap);
		mostrarArvoreERD(ap->dir);
	}
}
	
void mostrarArvoreRED(ArvoreBB ap){				//[6]
	if(ap != NULL){
		mostrarNo(ap);
		mostrarArvoreRED(ap->esq);
		mostrarArvoreRED(ap->dir);
	}
}

void mostrarArvoreEDR(ArvoreBB ap){				//[7]
	if(ap != NULL){
		mostrarArvoreEDR(ap->esq);
		mostrarArvoreEDR(ap->dir);
		mostrarNo(ap);
	}
}

void mostrarArvoreBFS(ArvoreBB ap){				//[8]
	No *p,*e,*d;
	int ok;
	Fila f;
	if(ap != NULL){
		p = ap;
		pushFila(&f,p);
		do{
			p = acessarFila(&f);
			mostrarNo(p);
			popFila(&f);
			e = p->esq;
			if(e != NULL){
				pushFila(&f,e);
			}
			d = p->dir;
			if(d != NULL){
				pushFila(&f,d);	
			}
			ok = verificarFilaVazia(&f);
		}while(ok != 1);
	}
}

int buscarNo(ArvoreBB ap,int valor){			//[9]
	No *p;
	p = ap;
	while((p != NULL) && (p->chave != valor)){
		if(p->chave > valor){
			p = p->dir;
		}
		else{
			p = p->esq;	
		}
	}
	return p;
}

ArvoreBB inserirNo(ArvoreBB ap,No* novo){		//[10]
	No *p,*ant;
	if(ap == NULL){
		ap = novo;
	}
	else{
		p = ap;
		while(p != NULL){
			ant = p;
			if(novo->chave < p->chave){			
				p = p->esq;
			}
			else if(novo->chave > p->chave){
				p = p->dir; 
			}
			else{
				p = NULL;
			}
		}
		if(novo->chave < ant->chave){
			ant->esq = novo;
		}
		else{
			ant->dir = novo;
		}
	}
	return ap;
}

ArvoreBB removerNo(ArvoreBB ap,int valor){		//[11]
	No *p,*pai;
	if(ap != NULL){
		p = ap;
		while((p != NULL) && (p->chave != valor)){
			pai = p;
			if(valor < p->chave){
				p = p->esq;
			}
			else if(valor > p->chave){
				p = p->dir;
			}
			else{
				p = p->chave;
			}
		}
		if(p != NULL){
			if(ap == p){
				ap = removerRaiz(ap);
			}
			else if(p == pai->esq){
					pai->esq = removerRaiz(pai->esq);
			}
			else{
				pai->dir = removerRaiz(pai->dir);
			}
		}
	}
	return ap;
}

ArvoreBB removerRaiz(ArvoreBB ap){				//[12]
	No *p,*pai,*maior;
	p = ap;
	if(ap != NULL){
		if((p->esq == NULL) && (p->dir == NULL)){
			p = NULL;
		}
		else if(p->esq == NULL){
			p = ap->dir;
		}
		else if(p->dir == NULL){
			p = ap->esq;
		}
		else{
			pai = ap;
			maior = ap->esq;
			while(maior->dir != NULL){
				pai = maior;
				maior = maior->dir;
			}
			if(pai != ap){
				pai->dir = maior->esq;
				maior->esq = ap->esq;
			}
			maior->dir = ap->dir;
			p = maior;
		}
		free(ap);
	}
	return p;
}

int determinarAltura(ArvoreBB ap){				//[13]
	int h,esq,dir; h = 0;
	if(ap != NULL){
		esq = determinarAltura(ap->esq);
		dir = determinarAltura(ap->dir);
		if(dir>esq){
			h = dir + 1;
		}
		else{
			h = esq + 1;
		}
	}
	else{
		h = -1;
	}
	return h;
}

No* obterPai(ArvoreBB ap,No *p){				//[14]
	No *pai,*ant; int ch;
    if((p != NULL) && (ap != NULL)){
   		while((ap != NULL) && (ch != 1)){
    		if(p->chave < ap->chave){
    			ant = ap;
    			ap = ap->esq;
			}
			else if(p->chave > ap->chave){
				ant = ap;
				ap = ap->dir;
			}
			else{
				ch = 1;
				pai = ant;
			}
		}
		if(ch == 0){
			pai = NULL;
		}
	}
    return pai;
}

No* obterAncestral(ArvoreBB ap,No* p,No* q){	//[15]
	No *anc, *aux;
	bool ok;
	anc = NULL;
		if((ap!=NULL) && (p!=NULL) && (q!=NULL)){
			anc = ap;
			ok = FALSE; aux = NULL;
			while(ok == FALSE){
				if((p->chave < anc->chave) && (q->chave < anc->chave)){
					aux = anc;
					anc = anc->esq;
				}
				else if((p->chave > anc->chave) && (q->chave > anc->chave)){
					aux = anc;
					anc = anc->dir;
				}
				else{
					ok = TRUE;
				}
			}
			if((anc->chave == p->chave) || (anc->chave == q->chave)){
				anc = aux;
			}
		}
	return anc;
}

No* obterSeguinte(ArvoreBB ap, No* p){			//[16]
	Pilha pilha;
	No *ant, *atual, *prox;
	atual = ap;
	bool vazio,achou;
	ant = NULL;
	prox = NULL;
	achou = FALSE;
	criarPilhaVazia(&pilha);
	if(ap != NULL){
		while(achou != FALSE){
			while(atual != NULL){
				pushPilha(&pilha,atual);
				atual = atual->esq;
			}
			vazio = verificarPilhaVazia(&pilha);
			if(vazio != 1){
				ant = acessarTopo(&pilha);
				popPilha(&pilha);
				if(ant->chave == p->chave){
					achou = TRUE;
					if(atual != NULL){
						while(atual != NULL){
							prox = atual;
							atual = atual->esq;
						}
					}
					else if((atual == NULL)&&(vazio != 1)){
						prox = acessarTopo(&pilha);
						if(prox->chave < ant->chave){
							prox = acessarTopo(&pilha);
							popPilha(&pilha);
						}
					}
				}
			}
		}
	}
	return prox;
}

