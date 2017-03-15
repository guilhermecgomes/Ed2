/* Caminhamentos em uma árvore binária */
/*
  Arquivo: AB_GuilhermeDoCarmoGomes.c
  Autor: Guilherme do Carmo Gomes
  Data: 13/03/17 08:17
  Descrição: Este programa implementa uma Árvore Binária para brincar.
  A função de construir liga uma raiz a duas árvores, esquerda e direita.
  Implementa também o caminhamento eRd recursivo.
  Exercício - a) Construir a árvore binária com os dados 1,2,3,4,5,6,7 conforme a saída  
                 fornecida pelo executável.
              b) Implementar o caminhamento Red e mostrar a mesma árvore 
                 por esse caminhamento.
              c) Implementar o caminhamento edR e mostrar a mesma árvore 
                 por esse caminhamento.
              d) Implementar o caminhamento por nível (bfs) e mostrar a mesma árvore 
                 por esse caminhamento.
*/
#include <stdio.h>
#include <stdlib.h>
#include "Booleano.h"
#include "FilaPointer.h"

typedef struct No{
        int elemento;            
        struct No * esq; 
        struct No * dir;
} No;

typedef No* Arvore;

void mostrarArvore_Red(Arvore);
void mostrarArvore_edR(Arvore);
Arvore criarArvoreVazia( );                 // cria a árvore vazia
Arvore construirArvore(int, Arvore, Arvore);// constroi a árvore, dado o valor da raiz e as duas árvores
void mostrarRaiz(Arvore);                   // mostra somente a raiz da árvore
void mostrarArvore(Arvore);                 // mostra todos os nós da árvore pelo caminhamento eRd      
bool verificarArvoreVazia(Arvore);          // devolve TRUE se a árvore é vazia

main(){
    Arvore raiz1,raiz2,raiz3;
    bool vazia;
	raiz1 = construirArvore(5,NULL,NULL);
    raiz2 = construirArvore(6,NULL,NULL);
    raiz3 = construirArvore(1,NULL,raiz1);
    raiz1 = construirArvore(3,raiz3,raiz2);
    raiz2 = construirArvore(7,NULL,NULL);
    raiz3 = construirArvore(4,raiz2,NULL);
    raiz2 = construirArvore(2,raiz1,raiz3);

    if (vazia == FALSE) {
		printf("\n\n arvore 3:  \n"); 
		mostrarArvore(raiz2);
		printf("\n");
		mostrarArvore_edR(raiz2);
	}
		else printf("\n\n arvore vazia \n");
    printf("\n\n");
    raiz1 = construirArvore(5,NULL,NULL);
    raiz2 = construirArvore(6,NULL,NULL);
    raiz3 = construirArvore(1,raiz1,NULL);
    raiz1 = construirArvore(4,raiz2,raiz3);
    raiz2 = construirArvore(7,NULL,NULL);
    raiz3 = construirArvore(3,NULL,raiz2);
    raiz2 = construirArvore(2,raiz1,raiz3);
    if (vazia == FALSE) {
		printf("\n\n arvore 4:  \n");
		mostrarArvore(raiz2);
		printf("\n");
		mostrarArvore_Red(raiz2);
	}
	    else printf("\n\n arvore vazia \n");
    printf("\n\n");
    system("PAUSE");
}

// IMPLEMENTAÇÕES

Arvore criarArvoreVazia( ){
     Arvore ap;
     ap = NULL;
     return ap;
}

Arvore construirArvore(int item, Arvore e, Arvore d){
       No *novo, *raiz;
       novo = (struct No*)malloc(sizeof(struct No));
       novo->elemento = item;
       novo->esq = e;
       novo->dir = d;
       raiz = novo;
       return raiz;
}

void mostrarRaiz(Arvore ap){
     if (ap != NULL) printf(" %d  ",ap->elemento);
}

bool verificarArvoreVazia(Arvore ap){
     bool ok;
     if (ap == NULL) ok = TRUE; else ok = FALSE;
     return ok;
}

void mostrarArvore(Arvore ap){ // eRd
       if (ap != NULL){
              mostrarArvore(ap->esq);
              mostrarRaiz(ap);
              mostrarArvore(ap->dir);}      
}

void mostrarArvore_edR(Arvore ap){
	if(ap != NULL){
		mostrarArvore_edR(ap->esq);
		mostrarArvore_edR(ap->dir);
		mostrarRaiz(ap);
	}
}

void mostrarArvore_Red(Arvore ap){
	if(ap != NULL){
		mostrarRaiz(ap);
		mostrarArvore_Red(ap->esq);
		mostrarArvore_Red(ap->dir);
	}
}

