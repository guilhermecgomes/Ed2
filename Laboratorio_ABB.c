/*
  Arquivo: ABB_PatoDonald.c
  Autor: Pato Donald
  Date: 21/03/10 08:19
  Descrição: Este programa implementa as operações elementares de  uma Árvore Binária de Busca:
  criação, busca, inserção e remoção.  Inserir não aceita duplicatas. Remover com as duas versões.
  Implementa também as funções obter Pai, ancestral,determinarAltura e eRd iterativo.
  Implementa ancestral recursivo.
*/
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>  /* a constante NULL está nesta biblioteca */
#include "PilhaPointer.h"
#include "FilaPointer.h"
#include "Booleano.h"

#define MaxNos 24

typedef struct No{
        int chave;
        char satelite;
        struct No * esq; 
        struct No * dir;
} No;

typedef No* ArvoreBB;

//protótipos No
   void mostrarNo(No*);							//[1]
   No* criarNo(int,char);						//[2]

// protótipos ArvoreBB
	ArvoreBB criarArvoreBB( );					//[3]
	bool verificarArvoreVazia(ArvoreBB);		//[4]
	void mostrarArvore(ArvoreBB);				//[5]
	void Red(ArvoreBB);							//[6]
	void edR(ArvoreBB);							//[7]
	void Bfs(ArvoreBB);							//[8]
	
	ArvoreBB inserirNo(ArvoreBB, No*);     	    // [9]  não recursivo	ok
	No* buscarNo(ArvoreBB, int);        	    // [10]  não recursivo	ok
	ArvoreBB removerRaiz(ArvoreBB);     	    // [11]  não recursivo	em desenvolvimento
	ArvoreBB removerNo(ArvoreBB, int);  	    // [12]  usando removerRaiz	em desenvolvimento
	int determinarAltura(ArvoreBB);    		    // [13] 	ok
    void mostrarArvoreERD(ArvoreBB);       		// [14]  não recursivo	em desenvolvimento
	No* obterPai(ArvoreBB, No*);           		// [15]	em desenvolvimento
	No* obterAncestral(ArvoreBB, No*, No*);     // [16]  não recursivo	em desenvolvimento
	No* obterAncestralRec(ArvoreBB, No*, No*);  // [17]  recursivo	em desenvolvimento

main(){
	setlocale(LC_ALL, "Portuguese");
    int chaves[MaxNos] = {30, 7, 40, 4, 20, 30, 50, 10, 22, 8, 12, 11, 5, 25, 24, 45, 60, 80, 3, 2, 1, 90, 100, 99};
    char satelites[MaxNos] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','X','Y'};
    ArvoreBB a = criarArvoreBB();
    ArvoreBB b = criarArvoreBB();
    No* no;
    int i;
    for(i = 0; i < MaxNos; i++){
        no = criarNo(chaves[i], satelites[i]);
        a = inserirNo(a, no);	
    }
      
    printf("Arvore:\n\n");printf("Arvore em eRd - Recursivo\n");  		mostrarArvore(a);
    printf("\n\n");		  printf("Arvore em eRd - Não recursivo\n");    mostrarArvoreERD(a);
	printf("\n\n");		  printf("Arvore em Bfs - Não recursivo\n");	Bfs(a);
	printf("\n\n");		  printf("Arvore em edR - Recursivo\n");		edR(a);
	printf("\n\n");       printf("Arvore em Red - Recursivo\n");		Red(a);

	
	////    altura	   ////
	int altura;
	altura = determinarAltura(a);
	printf("\nAltura da arvore:%d",altura);
	////    altura	   ////
	
    ////	buscar nó	////
	int valor;
	printf("\nQual o valor para procurar:");
	scanf("%d",&valor);
	no = buscarNo(a,valor);
	if(no == NULL){
		printf("Não existe");
	}
	else{
		printf("\n\nEncontrei no S,atelite %c ",no->satelite);	
	}
    ////	buscar nó  //// 
    //// remover raiz  ////
	a = removerRaiz(a);
	printf("Arvore:\n\n");printf("Arvore em Bfs - Não recursivo\n");	Bfs(a);
    //// remover raiz  ////
    //// remover no	   ////
    int valor1;
    printf("\nQual nó remover ?");
    scanf("%d",&valor1);
    a = removerNo(a,valor1);
    printf("Arvore:\n\n");printf("Arvore em Bfs - Não recursivo\n");	Bfs(a);
    //// remover no    ////

	
    printf("\n\n");
    system("PAUSE");
}

// implementações das funções de No       
void mostrarNo(No *p){		//[1]
     if (p != NULL){ printf(" |%d|%c| ",p->chave, p->satelite);}
     else printf("no inexistente \n\n");
}

No* criarNo(int c, char ch){				//[2]
   No* aux;
   aux = (struct No*) malloc(sizeof(struct No));
   aux->chave = c; aux->satelite = ch;
   aux->esq = NULL;  aux->dir = NULL;
   return aux;    
}
               
// implementações das funções de ArvoreBB               
ArvoreBB criarArvoreBB( ){	//	ok				//[3]
     ArvoreBB ap;
     ap = NULL;
     return ap;
}

bool verificarArvoreVazia(ArvoreBB ap){	//	ok				//[4]
    bool ok;
    if (ap == NULL){
		ok = TRUE;
	}
	else{
		ok = FALSE;
	}
    return ok;
}

void mostrarArvore(ArvoreBB ap){   // caminhamento eRd RECURSIVO //	ok		//[5]
    if (ap != NULL){
        mostrarArvore(ap->esq);
        mostrarNo(ap);
        mostrarArvore(ap->dir);
        }
}

void Red(ArvoreBB ap){				//[6]
	if(ap != NULL){
		mostrarNo(ap);
		mostrarArvore(ap->esq);
		mostrarArvore(ap->dir);
	}
}

void edR(ArvoreBB ap){				//[7]
	if(ap != NULL){
		mostrarArvore(ap->esq);
		mostrarArvore(ap->dir);
		mostrarNo(ap);
	}
}

void Bfs(ArvoreBB a){				//[8]
	Fila f;
	No *p, *e,*d;
	int ok;
	criarFilaVazia(&f);
	if(a != NULL){
		p = a;
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
			if(d!=NULL){
			  	pushFila(&f,d);
			}
			ok = verificarFilaVazia(&f);
		}while(ok != 1);
	}
}
           
ArvoreBB inserirNo(ArvoreBB ap, No* novo){ // [9]	ok
	No *p, *ant;
	if (ap == NULL) ap = novo;  // árvore vazia
    else {
		p = ap;
        while (p != NULL){
			ant = p;
			if (novo->chave < p->chave){
				p = p->esq;
			}
			else if (novo->chave == p->chave){
				p = NULL;
			}
            else{
            	 p = p->dir;	
			}
        } // fim while
		if (novo->chave < ant->chave){
			ant->esq = novo;
		} 
        else if (novo->chave > ant->chave){
        	ant->dir = novo;
		} 
	}  // fim else 
    return ap;
}

No* buscarNo(ArvoreBB ap, int valor){	//  [10]	ok
    No * p;
    p = ap;
    	while((p != NULL) && (p->chave != valor)){
    		if(valor > p->chave){
    			p = p->dir;
			}
			else{
				p = p->esq;
			}
		}
    return p;
}

ArvoreBB removerRaiz(ArvoreBB raiz){	//[11]
    No *q,*pai,*maior;
    q = raiz;
    if(raiz != NULL){
    	if((raiz->esq == NULL)&&(raiz->dir == NULL)){
    		q = NULL;
		}
		else if(raiz->dir == NULL){
			q = raiz->esq;
		}
		else if(raiz->esq == NULL){
			q = raiz->dir;
		}
		else{
			pai = raiz;
			maior = raiz->esq;
			while(maior->dir != NULL){
				pai = maior;
				maior = maior->dir;
			}
			if(pai != raiz){
				pai->dir = maior->esq;
				maior->esq = raiz->esq;
			}
			maior->dir = raiz->dir;
			q = maior;
		}
		free(raiz);	
	}
    return q;              
}

ArvoreBB removerNo(ArvoreBB ap, int valor){		//[12]
	No *q,*pai;
	if(ap != NULL){
		q = ap;
		while((q->chave != valor) && (q != NULL)){
			pai = q;
			if(valor > q->chave){
				q = q->dir;
			}
			else{
				q = q->esq;
			}
		}
		if(q != NULL){
			if(q == ap){
				ap = removerRaiz(ap);
			}
			else{
				if(q == pai->esq){
					pai->esq = removerRaiz(pai->esq);
				}
				else{
					pai->dir = removerRaiz(pai->dir);
				}
			}
		}
	}
	return ap;
}

int determinarAltura(ArvoreBB ap){	//	[13]	ok
    int h,esq,dir;	h = 0;
    if(ap != NULL){
    	esq = determinarAltura(ap->esq);
    	dir = determinarAltura(ap->dir);
    	if(dir > esq){
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

void mostrarArvoreERD(ArvoreBB ap){  // [14]caminhamento eRd NÃO RECURSIVO
	Pilha aux;
	criarPilhaVazia(&aux);
	No *p;
	p = ap; bool fim = FALSE;
	if(ap != NULL){
		do{
			while(p!=NULL){ //coloco na pilha até bater no fim da arvore
				pushPilha(&aux,p);		
				p = p->esq; //ponteiro corre para a esqueda
			}
			if(verificarPilhaVazia(&aux) != TRUE){
				p = acessarTopo(&aux);
				mostrarNo(p);
				popPilha(&aux);
				p = p->dir;
			}
			else{
				fim = TRUE;
			}
		}while(fim != TRUE);
	}
}

No* obterPai(ArvoreBB ap, No *p){
    No *pai,*ant; int ch;
    if(ap != NULL){
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

No* obterAncestral(ArvoreBB ap, No* p, No* q){
    No *anc, *pai1, *pai2;
    	if(ap!=NULL){
    		if(p==ap || q==ap) anc=NULL;
    		else{
    			No *mn, *n1, *n2;int ch=0;
    			mn=ap;n1=ap;n2=ap;
    			while(ch!=1){
    				if((((p->chave < mn->chave) && (q->chave > mn->chave)) || ((p->chave > mn->chave) && (q->chave < mn->chave)))){
    					anc=mn;
						ch=1;
					}
					else{
						if(p->chave < n1->chave){ 
							pai1=n1;
							n1=n1->esq; 
						}
						else if(p->chave > n1->chave){ 
							pai1=n1;
							n1=n1->dir;  
						}		
					
						if(q->chave < n2->chave){ 
							pai2=n2;
							n2=n2->esq;
						}
						else if(q->chave > n2->chave){ 
							pai2=n2;
							n2=n2->dir; 
						}
					
						if(pai1->esq==pai2 || pai1->dir==pai2) { 
							anc=pai1; 
							ch=1; 
						}
						else if(pai2->esq==pai1 || pai2->dir==pai1) { 
							anc=pai2;
							ch=1; 
						}		
						mn=n1;
					}
				}
			}
		}
		return anc;
}

No* obterAncestralRec(ArvoreBB ap, No* p, No* q){
    No *anc;
    printf("\n em desenvolvimento \n");
    return anc;
}
