//ä`ö®»ÌQ
#include<stdio.h>
#include<math.h>
#define f(x) cos(x)*cos(x) //íÏªÖ

int main(void){
	double a,b,x,x1,dx,s,s1,deg;
	int i,n;
	
	printf("px(deg)ðüÍ. deg=");
	scanf("%lf",&deg);
	printf("ªðüÍ. n=");
	scanf("%d", &n);
	
	s=0; //
	a=0; //ÏªJn_
	b=deg*(M_PI/180); //ÏªI¹_, radÉÏ·
	
	dx=(b-a)/n; //Ý
	
	for (i=0;i<n;i++){
		x=a+i*dx;
		x1=x+dx;
		s1=((f(x)+f(x1))/2)*dx; //÷¬ÊÏ
		s += s1; //°
	}
	
	printf("n=%d s=%f\n", n,s);
	
	return 0;
}