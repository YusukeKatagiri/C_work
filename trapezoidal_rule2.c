//��`�������̂Q
#include<stdio.h>
#include<math.h>
#define f(x) cos(x)*cos(x) //��ϕ��֐�

int main(void){
	double a,b,x,x1,dx,s,s1,deg;
	int i,n;
	
	printf("�p�x(deg)�����. deg=");
	scanf("%lf",&deg);
	printf("�����������. n=");
	scanf("%d", &n);
	
	s=0; //
	a=0; //�ϕ��J�n�_
	b=deg*(M_PI/180); //�ϕ��I���_, rad�ɕϊ�
	
	dx=(b-a)/n; //���ݕ�
	
	for (i=0;i<n;i++){
		x=a+i*dx;
		x1=x+dx;
		s1=((f(x)+f(x1))/2)*dx; //�����ʐ�
		s += s1; //��
	}
	
	printf("n=%d s=%f\n", n,s);
	
	return 0;
}