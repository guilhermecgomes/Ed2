#include <stdlib.h>        // aqui se encontra a função rand
#include <stdio.h>
#include <time.h>
#include <windows.h>

#define low 1
#define high 100000000

#define N 707


typedef struct{
  int elemento[N];
} ListaInt;

ListaInt inserirNoFim(ListaInt,int);
ListaInt sorting(ListaInt);
ListaInt criarListaVazia();
int buscarLista(ListaInt,int);
int buscarRecursivo(ListaInt,int,int);
ListaInt construirListaAleatoria(int,int,int);
void mostrarLista(ListaInt);
int InteiroRandomico(int,int);

main(){
    ListaInt A;	int i,j/*,ok1*/,ok2,tam;
    tam = N-1;
    clock_t inicio,fim;
    double pf;
    A = criarListaVazia();
    //A = construirListaAleatoria(N,low,high);
    for(i=1;i<=N;i++){
		A = inserirNoFim(A,i);
	}
	
	//printf(" Lista A ");
    mostrarLista(A);
    //printf("\n\n\n");
    printf("acho que passou: ");
	scanf("%d",&j);
	//inicio = clock();
	//ok1 = buscarLista(A,j);
	//fim = clock();
	//pf = (double)(fim-inicio)/CLOCKS_PER_SEC;
	//printf("intervalo de tempo = %2.5f \n\n",pf);
	//inicio = clock();
	inicio = GetTickCount(); 
	ok2 = buscarRecursivo(A,j,tam);
	//fim = clock();
	fim = GetTickCount();
	pf = fim - inicio;
	//pf = (double)(fim-inicio)/CLOCKS_PER_SEC;
	printf("intervalo de tempo = %2.5f \n\n",pf);
    //A = sorting(A);
    //if(ok1 == 1){
    //	printf("SUCESSO");
	//}
	//	else{
	//		printf("FRACASSO");
	//	}
	if(ok2 == 1){
   	printf("SUCESSO");
	}
		else{
			printf("FRACASSO");
		}
	printf("\n\n\n");    
    system("PAUSE");
}

int buscarRecursivo(ListaInt A,int j, int tam){
	int ok; ok = 0;
	if(tam != -1){
		if(j == A.elemento[tam]){
		ok = 1;
		}else {
			tam = tam -1;
			ok = buscarRecursivo(A,j,tam);
		}
	}
	return ok;
}
   
int buscarLista(ListaInt A,int j){
	int i,ok; i = 0; ok = 0;
	while ((i < N) && (j != A.elemento[i])){
		i++;
	}
	if(j == A.elemento[i]){
		ok = 1;
	}
	return ok;
}     
        
int InteiroRandomico(int lo, int hi){          // gera um número aleatório na faixa [lo,hi]
    int r;
    double g;
    g = (double)rand()/((double)RAND_MAX + 1);
    r = g*(hi-lo+1) + lo;
    return r;
}
         
ListaInt criarListaVazia(){  // a posição zero armazena o tamanho da lista
        ListaInt L;
        L.elemento[0] = 0;
        return L;
}
       
void mostrarLista(ListaInt L){
    int i,n;
    n = L.elemento[0]; 
    if (n != 0) {
        printf("\n"); 
        for (i=1; i<=n; i++) printf(" %d ",L.elemento[i]);
    } 
    else printf(" \n LISTA VAZIA \n");                
}
        
ListaInt construirListaAleatoria(int M,int lo, int hi){
        ListaInt L;
        int numero, i;
        srand((int) time(NULL));
        L.elemento[0]=M;
        for(i=1;i<=M;i++){
		 	numero=InteiroRandomico(lo,hi);
		 	L.elemento[i]=numero;
		}
		return L;
}    

ListaInt inserirNoFim(ListaInt L,int y){
	int tam;
	L.elemento[0] = L.elemento[0]+ 1;
	tam = L.elemento[0];
	L.elemento[tam] = y;
	return L;
}

ListaInt sorting(ListaInt L){
         int k,j,aux,u,p;
         u = L.elemento[0]; p = 1;
         for(k=1; k<=(u-p); k++)
                  for(j=p; j<=(u-k); j++)
                           if(L.elemento[j]>L.elemento[j+1]){
                           aux = L.elemento[j]; L.elemento[j] = L.elemento[j+1]; L.elemento[j+1] = aux;
                           }
         return L;
}  
