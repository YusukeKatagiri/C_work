//angle.c
//deg����rad�ւ̕ϊ�

#include<stdio.h>
#include<math.h>

int main(void){
	
	double rad,deg;
	double pai=acos(-1.0);
	
	printf("�p�x(deg)����͂��Ă��������Bdeg=");
	scanf("%lf",&deg);
		rad=deg*(pai/180);
	printf("rad=%f\n",rad);
	
	return 0;
}