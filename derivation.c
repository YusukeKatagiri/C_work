//1階微分を差分を用いて計算
 #include<stdio.h>
 #include<math.h>
 #define f(x) sin(x)
 
 int main(){
 	double x,x1,x2,dx,f0,f1,f2,f3;
 	
 	printf("xを入力してください. x=");
 	scanf("%lf",&x);
 	
 	dx=0.01;
 	x1=x-dx;
 	x2=x+dx;
 	
 	f1=(f(x2)-f(x))/dx;
 	f2=(f(x)-f(x1))/dx;
 	f3=(f(x2)-f(x1))/(2*dx);
 	f0=cos(x);
 	
 	printf("前進差分 f1=%f\n",f1);
 	printf("後退差分 f1=%f\n",f2);
 	printf("中心差分 f1=%f\n",f3);
 	printf("正確な値 f1=%f\n",f0);
 }