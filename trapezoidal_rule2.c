//台形公式その２
#include<stdio.h>
#include<math.h>
#define f(x) cos(x)*cos(x) //被積分関数

int main(void){
	double a,b,x,x1,dx,s,s1,deg;
	int i,n;
	
	printf("角度(deg)を入力. deg=");
	scanf("%lf",&deg);
	printf("分割数を入力. n=");
	scanf("%d", &n);
	
	s=0; //
	a=0; //積分開始点
	b=deg*(M_PI/180); //積分終了点, radに変換
	
	dx=(b-a)/n; //刻み幅
	
	for (i=0;i<n;i++){
		x=a+i*dx;
		x1=x+dx;
		s1=((f(x)+f(x1))/2)*dx; //微小面積
		s += s1; //Σ
	}
	
	printf("n=%d s=%f\n", n,s);
	
	return 0;
}