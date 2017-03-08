#include <stdio.h>

//interface
int Pote(int,int);
int fat(int);
int mdc1(int,int);
int mdc2(int,int);

main(){
	int ya,yb,yc,yd;
	ya = Pote(6,3);
	yb = Fat(6);
	yc = mdc1(24,16);
	yd = mdc2(24,16);
	int a,b,c;
	scanf("%d",&a);
	scanf("%d",&b);
	c = a%b;
	printf("valor do porcentagem = %d\n",c);
	printf("A valor de y:%d\n",ya);
	printf("B valor de y:%d\n",yb);
	printf("C valor de y:%d\n",yc);
	printf("D valor de y:%d\n",yd);
	system("pause");
}
//implementação

Pote(int a,int n){
	int pot,y;
	if(n==0){
		pot = 1;
	}
		else if(n==1){
			pot = a;
		}
			else if(n%2==0){
			y = Pote(a,n/2);
			pot = y*y;
			} //fim if
	else{
		y = Pote(a,n-1);
		pot = a*y;
	} // fim else
	return pot;
}
Fat(int n){
	int f;
	if(n==0){
		f=1;
	}
	else{
		f = n*Fat(n-1);
	}
	return f;
}
mdc1(int m,int n){
	int a,d;
	if(m==0){
		a=n;
	}
	else if(m>n){
		a = mdc1(n,m);
	}
		else{
			d = n-m;
			a = mdc1(m,d);
		} // fim else
	return a;
}
mdc2(int m,int n){
	int a,r;
	if(m%n == 0){
		a=n;
	}
	else{
		r = m%n;
		a = mdc2(n,r);
	} // fim else
	return a;
}
