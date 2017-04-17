#include <stdio.h>
#include <stdlib.h>
#include "FilaPointer.h"
#include "PilhaPointer.h"
#include "Booleano.h"

typedef struct No{
	int elemento;
	struct No * dir;
	struct No * esq;
} No;

typedef No* Arvore;


//prototipos das funções 

Arvore criarArvore();							//criar arvore vazia
bool verificarArvoreVazia(Arvore);				//verifica se a arvore é vazia
void mostrarRaiz(Arvore);						//mostra a raiz da arvore
void eRd(Arvore);								//mostra a arvore inteira no ordem eRd
void Red(Arvore);								//mostra a arvore inteira no ordem Red
void edR(Arvore);								//mostra a arvore inteira no ordem edR
void bfs(Arvore);								//mostra a arvore inteira na order bfs
void eRdNRecursivo(Arvore);						//mostra a arvore inteira no ordem eRd //Não Recursivo
Arvore construirArvore(int,Arvore,Arvore);		//constroi a arvore
int contarNo(Arvore);							//conta o numero de nos de uma arvore
int contarNoNRecursivo(Arvore);					//conta o numero de nos de uma arvore //Não Recursivo

main(){
	Arvore ap,raiz1,raiz2,raiz3,raiz4; bool ok;
	ap = criarArvore();
	ok = verificarArvoreVazia(ap);
	if(ok == FALSE){
		printf("Arvore cheia");
	}
	else{
		printf("Arvore vazia");	
	}
	
	printf("\n");	
	raiz1 = construirArvore(6,NULL,NULL);
    raiz2 = construirArvore(5,NULL,raiz1);
    raiz1 = construirArvore(3,NULL,NULL);
    raiz3 = construirArvore(1,raiz1,raiz2);
	raiz1 = construirArvore(7,NULL,NULL);
	raiz2 = construirArvore(4,NULL,raiz1);
    
    raiz4 = construirArvore(2,raiz3,raiz2);

	eRd(raiz4);
	printf("\neRd:  ");
	eRdNRecursivo(raiz4);
	printf("\nRed:  ");
	Red(raiz4);
	printf("\nedR:  ");
	edR(raiz4);
	printf("\nBfs:  ");
	bfs(raiz4);
	printf("\n");
	
	int quant;
	quant = contarNoNRecursivo(raiz4);
	printf("\n%d",quant);
	quant = contarNo(raiz4);
	printf("\n%d",quant);
	printf("\n");
	system("PAUSE");
}

//implementações

Arvore criarArvore(){
	Arvore ap;
	ap = NULL;
	return ap;
}

bool verificarArvoreVazia(Arvore ap){
	bool ok; ok = FALSE;
	if(ap == NULL){
		ok = TRUE;
	}
	return ok;
}

void mostrarRaiz(Arvore ap){
	if(ap != NULL){
		printf(" %d ",ap->elemento);
	}
}

void eRd(Arvore ap){
	if(ap != NULL){
		eRd(ap->esq);
		mostrarRaiz(ap);
		eRd(ap->dir);
	}
}

void Red(Arvore ap){
	if(ap != NULL){
		mostrarRaiz(ap);
		Red(ap->esq);
		Red(ap->dir);
	}
}

void edR(Arvore ap){
	if(ap != NULL){
		edR(ap->esq);
		edR(ap->dir);
		mostrarRaiz(ap);
	}
}

void bfs(Arvore ap){
	Fila f;
	No *p,*e,*d;
	int ok;
	criarFilaVazia(&f);
	if(ap != NULL){
		p = ap;
		pushFila(&f,p);
		do{
			p = acessarFila(&f);
			mostrarRaiz(p);
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

void eRdNRecursivo(Arvore ap){
	Pilha b;
	No *p;
	int ok;
	criarPilhaVazia(&b);
	if(ap != NULL){
		p = ap;
		do{
			while(p != NULL){
				pushPilha(&b,p);
				p = p->esq;
			}
			ok = verificarPilhaVazia(&b);
			if(ok == 0){
				p = acessarTopo(&b);
				mostrarRaiz(p);
				popPilha(&b);
				p = p->dir;
			}
		}while(ok != 1);
	}
}

Arvore construirArvore(int item,Arvore e,Arvore d){
	No *novo, *raiz;
    novo = (struct No*)malloc(sizeof(struct No));
    novo->elemento = item;
	novo->esq = e;
    novo->dir = d;
    raiz = novo;
    return raiz;	
}

int contarNo(Arvore ap){
	int quant;	quant = 0;
	if(ap != NULL){
		quant += contarNo(ap->esq);
		quant = quant + 1;
		quant += contarNo(ap->dir);
	}
	return quant;
}

int contarNoNRecursivo(Arvore ap){
	Fila f;
	No *p,*e,*d;
	int ok, quant; quant = 0;
	criarFilaVazia(&f);
	if(ap != NULL){
		p = ap;
		pushFila(&f,p);
		do{
			p = acessarFila(&f);
			quant = quant + 1;
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
	return quant;
}

