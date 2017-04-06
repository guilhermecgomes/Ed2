#include <stdio.h>
#include "Booleano.h"



typedef struct No{
	int chave;	//item da arvore
	char satelite;	//
	struct No* esq;
	struct No* dir; 
} No;
typedef No* Arvorebb;


//assinatura

void mostrarNo(No*);
No* criarNo(int,char);
Arvorebb criarArvorebb();
bool verificarArvorebbVazia(Arvorebb);
//implementações

main(){
	No* p;	Arvorebb a;	bool ok;
	p = criarNo(1,'c');
	mostrarNo(p);
	a = criarArvorebb();
	ok = verificarArvoreVazia(a);
	printf("%d",ok);
}

bool verificarArvorebbVazia(Arvorebb a){
	bool ok;
	if(a != NULL){
		ok = FALSE;
	}else{
		ok = TRUE;
	}
	return ok;
}


Arvorebb criarArvorebb(){
	Arvorebb a;
	a = NULL;
	return a;
}

void mostrarNo(No *p){
	if(p!=NULL){
		printf(" %d %c", p->chave, p->satelite);
	}
	else printf("No inexistente \n\n");
}

No* criarNo(int c, char ch){
   No* aux;
   aux = (struct No*) malloc(sizeof(struct No));
   aux->chave = c; 
   aux->satelite = ch;
   aux->esq = NULL;  
   aux->dir = NULL;
   return aux;    
}

