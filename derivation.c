//1�K������������p���Čv�Z
 #include<stdio.h>
 #include<math.h>
 #define f(x) sin(x)
 
 int main(){
 	double x,x1,x2,dx,f0,f1,f2,f3;
 	
 	printf("x����͂��Ă�������. x=");
 	scanf("%lf",&x);
 	
 	dx=0.01;
 	x1=x-dx;
 	x2=x+dx;
 	
 	f1=(f(x2)-f(x))/dx;
 	f2=(f(x)-f(x1))/dx;
 	f3=(f(x2)-f(x1))/(2*dx);
 	f0=cos(x);
 	
 	printf("�O�i���� f1=%f\n",f1);
 	printf("��ލ��� f1=%f\n",f2);
 	printf("���S���� f1=%f\n",f3);
 	printf("���m�Ȓl f1=%f\n",f0);
 }