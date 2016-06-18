/*二次方程式の解を求めるプログラム*/
#include<stdio.h>
#include<math.h>

int main(){
	
	double a,b,c,D,result1,result2;
	
	printf("ax^2+bx+c=0の係数を入力してください");
	printf("a=");
	scanf("%lf",&a);
	
	printf("b=");
	scanf("%lf",&b);
	
	printf("c=");
	scanf("%lf",&c);
	
	D=(b*b-4*a*c); /*判別式*/
	
	/*(判別式)>0*/
	if(D>0){ 
		result1 = (-b + sqrt(D))/2*a;
		result2 = (-b - sqrt(D))/2*a;
		printf("result1 = %f と result2 = %f \n",result1,result2);
	/*(判別式)=0*/
	}else if(D==0){
		result1 = (-b -sqrt(D))/2*a;
		printf("result1 = %f \n",result1);
	/*(判別式)<0*/
	}else{
		double real,imag;
		real = -b/2*a;
		imag = sqrt(-D)/2*a;
		printf("result1=%f+%fi,result2=%f-%fi \n", real,imag,real,imag);
	}
	
	return 0;
}
