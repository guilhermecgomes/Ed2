/* Caminhamentos em uma �rvore bin�ria */
/*
  Arquivo: AB_<seu nome aqui>.c
  Autor: PATO DONALD
  Data: 20/03/11 11:49
  Descri��o: Este programa implementa uma �rvore Bin�ria para brincar.
  A fun��o de construir liga uma raiz a duas �rvores, esquerda e direita.
  Implementa tamb�m o caminhamento eRd recursivo.
  Exerc�cio - a) Construir a �rvore bin�ria com os dados 1,2,3,4,5,6,7 conforme a sa�da  
                 fornecida pelo execut�vel.
              b) Implementar o caminhamento Red e mostrar a mesma �rvore 
                 por esse caminhamento.
              c) Implementar o caminhamento edR e mostrar a mesma �rvore 
                 por esse caminhamento.
              d) Implementar o caminhamento por n�vel (bfs) e mostrar a mesma �rvore 
                 por esse caminhamento.
*/

#include <stdlib.h>
#include "Booleano.h"
#include "FilaPointer.h"

typedef struct No{
        int elemento;            
        struct No * esq; 
        struct No * dir;
} No;

typedef No* Arvore;

Arvore criarArvoreVazia( );                 // cria a �rvore vazia
Arvore construirArvore(int, Arvore, Arvore);// constroi a �rvore, dado o valor da raiz e as duas �rvores
void mostrarRaiz(Arvore);                   // mostra somente a raiz da �rvore
void mostrarArvore(Arvore);                 // mostra todos os n�s da �rvore pelo caminhamento eRd      
bool verificarArvoreVazia(Arvore);          // devolve TRUE se a �rvore � vazia

main(){
       Arvore a;
       bool vazia;
       a = criarArvoreVazia();
       vazia = verificarArvoreVazia(a);
       if (vazia == FALSE) {printf("\n\n arvore a:  \n"); mostrarArvore(a);}
       else printf("\n\n arvore vazia \n");

       printf("\n\n");
       system("PAUSE");
       }

// IMPLEMENTA��ES

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
     if (ap != NULL) printf(" %d  \n",ap->elemento);
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

