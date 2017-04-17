#include <stdlib.h>
#include "PilhaPointer.h"
#include "FilaPointer.h"
#include "Booleano.h"
#include <stdio.h>
#define MaxNos 18

typedef struct No{
        int chave;
        char satelite;
        struct No * esq; 
        struct No * dir;
} No;

typedef No* ArvoreAVL;

//protótipos No
   void mostrarNo(No*);
   No* criarNo(int,char);

// protótipos ArvoreAVL
	ArvoreAVL criarArvoreAVL( );
	bool verificarArvoreVazia(ArvoreAVL);
	void mostrarArvore(ArvoreAVL);
	void Red(ArvoreAVL);
	void edR(ArvoreAVL);
	void bfs(ArvoreAVL);
	ArvoreAVL inserirNo(ArvoreAVL, No*);           
	No* buscarNo(ArvoreAVL, int);                  
	ArvoreAVL removerRaiz(ArvoreAVL);               
	ArvoreAVL removerNo(ArvoreAVL, int);           
	int determinarAltura(ArvoreAVL);
	ArvoreAVL rodarEsquerda(ArvoreAVL,No*);
	ArvoreAVL rodarDireita(ArvoreAVL,No*);
	ArvoreAVL DuplaEsquerdaDireita(ArvoreAVL,No*);    
main(){
	
       int chaves[7] = {8,4,14,2,7,10,19};
       char satelites[7] = {'A','B','C','D','E','F','G'};
       ArvoreAVL a = criarArvoreAVL();
       No* no; 
	   int h;
       int i;
       
       for(i = 0; i < 7; i++){
             no = criarNo(chaves[i], satelites[i]);
             a = inserirNo(a, no);
       }
       printf("Arvore:\n");   bfs(a);
       printf("\n-----------------------------------------\n");
       no = buscarNo(a,8);
	   a = DuplaEsquerdaDireita(a,no);
	   bfs(a);
	   printf("\n");
	   //teste rodarEsquerda
	   
       system("PAUSE");
}

// implementações das funções de No       
void mostrarNo(No *p){
     if (p != NULL){ printf(" %d %c ",p->chave, p->satelite);}
     else printf("no inexistente \n\n");
}

No* criarNo(int c, char ch){
   No* aux;
   aux = (struct No*) malloc(sizeof(struct No));
   aux->chave = c; aux->satelite = ch;
   aux->esq = NULL;  aux->dir = NULL;
   return aux;    
}
               
// implementações das funções de ArvoreAVL               
ArvoreAVL criarArvoreAVL( ){
     ArvoreAVL ap;
     ap = NULL;
     return ap;
}
bool verificarArvoreVazia(ArvoreAVL ap){
     bool ok;
     if (ap == NULL) ok = TRUE; else ok = FALSE;
     return ok;
}

ArvoreAVL inserirNo(ArvoreAVL ap, No* novo){ // Nao aceita duplicata
	   No* ant; int ch;
	   No* p; ch = 0;
	   if(ap == NULL ) ap = novo;
	   else{
	   	  p = ap;
	   	  while((p != NULL) && (ch==0)){
	   	  	 if(novo->chave < p->chave ) {
	   	  	 	  ant = p;
				  p = p->esq;
	   	  	 }
	   	  	 else if(novo->chave > p->chave) {
	   	  	 	  ant = p;
				  p = p->dir;
	   	  	 } 
	   	  	 else ch=1;
	   	  }
	   	  if(ch==0){
	   	      if(novo->chave < ant->chave) ant->esq = novo;
	   	      else ant->dir = novo;
	        }
	   }
   return ap;
}


ArvoreAVL removerRaiz(ArvoreAVL raiz){
        No *q,*pai,*maior;
         q = raiz;
         if(raiz != NULL){
         	if((raiz->esq == NULL) && (raiz->dir == NULL)){
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

ArvoreAVL removerNo(ArvoreAVL ap, int valor){ 
    No *pai,*q;
    if(ap!=NULL){
        q=ap;
        while((q->chave!=valor) && (q != NULL)){
            pai=q;
            if(valor > q->chave)q=q->dir;
            else q=q->esq;
        }
        if(q!=NULL){
            if(q==ap) ap=removerRaiz(ap);
            else{
                if(q == pai->esq){
                	pai->esq=removerRaiz(pai->esq);
                }
                else pai->dir=removerRaiz(pai->dir);
            }
        }
    }
    return ap;
}

No* buscarNo(ArvoreAVL ap, int valor){
       No * p; int ch;
       ch = 0; p = ap;
       while((p != NULL)&&(ch==0)){
       	if(p->chave == valor) ch=1;
       	else{
       		if(valor < p->chave ) p = p->esq;
       		else p = p->dir;
       	}
       }
       if(ch==0) p = NULL;
       return p;
}
int determinarAltura(ArvoreAVL ap){  //recursivo
    int h; int he; int hd;
    if(ap == NULL) h = -1;
    else{
    	he = determinarAltura(ap->esq);
    	hd = determinarAltura(ap->dir);
    	if(he < hd) h = hd+1;
    	else h = he+1;
    }
    return h;
}

void mostrarArvore(ArvoreAVL ap){   // caminhamento eRd RECURSIVO
     if (ap != NULL){
            mostrarArvore(ap->esq);
            mostrarNo(ap);
            mostrarArvore(ap->dir); 
     }
}

void Red(ArvoreAVL t){ //Red
	if(t!=NULL){
		mostrarNo(t);
		Red(t->esq);
		Red(t->dir);
	}
}

void edR(ArvoreAVL t){ //edR
	 if(t!=NULL){
		edR(t->esq);
		edR(t->dir);
		mostrarNo(t);
	}
}

void bfs(ArvoreAVL a){
    int ok=0;
    No * p, *e, *d;
    p = criarArvoreAVL();
    e = criarArvoreAVL();
    d = criarArvoreAVL();
    Fila f;
    criarFilaVazia(&f);
    if(a!=NULL){
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
                   if(d != NULL){
                        pushFila(&f,d);
                   }
                   ok = verificarFilaVazia(&f);
             }while(ok != 1 );
    }
}
ArvoreAVL rodarEsquerda(ArvoreAVL ap, No *x){
          No *y,*ant,*p; ant = NULL;
          if((ap != NULL) &&(x!=NULL)){
                if(x->dir != NULL){
                          p = ap;
                          while((p != x) && (p != NULL)){
                                   ant = p;
                                   if(x->chave < p->chave){
                                               p = p->esq;
                                   }else if(x->chave > p->chave){
                                               p = p->dir;
                                   }
                          }
                          if(p!=NULL){
						  
	                          y = x->dir;
	                          x->dir = y->esq;
	                          y->esq = x;
	                          if(x != ap){
	                               if(y->chave < ant->chave){
	                                               ant->esq = y;
	                               }else if(y->chave > ant->chave){
	                                     ant->dir = y;
	                               }
	                          }else{
	                                ap = y;
	                          }
                      	  }
                }
          }
          return ap;
}
ArvoreAVL rodarDireita(ArvoreAVL ap, No*y){
	No *x,*p,*ant;
	if((ap != NULL)&&(y != NULL)){
		p = ap;
		if(y->esq != NULL){
			while((p!=NULL) && (p->chave != y->chave)){
				if(p->chave > y->chave){
					ant = p;
					p = p->esq;
				}
				else{
					ant = p;
					p = p->dir;
				}
			}
			if(p!=NULL){
				x = y->esq;
				y->esq = x->dir;
				x->dir = y;
				if(y!=ap){
					if(x->chave < ant->chave){
						ant->esq = x;
					}
					else if(x->chave > ant->chave){
						ant->dir = x;
					}
				}
				else{
					ap = x;
				}
			}
		}
	}
	return ap;
}
ArvoreAVL DuplaEsquerdaDireita(ArvoreAVL ap, No*x){
	No *p,*y,*z;
	if((ap != NULL) &&(x!=NULL)){
    	p = ap;
        while((p != x) && (p != NULL)){
            if(x->chave < p->chave){
            	p = p->esq;
            }
			else if(x->chave > p->chave){
            	p = p->dir;
            }
        }
        if(p!=NULL){
			y = p->esq;
			z = y->esq;
			y = rodarEsquerda(ap,y);
			p = rodarDireita(ap,x);
		}
	}
		return p;
		
}
