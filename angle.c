//angle.c
//degからradへの変換

#include<stdio.h>
#include<math.h>

int main(void){
	
	double rad,deg;
	double pai=acos(-1.0);
	
	printf("角度(deg)を入力してください。deg=");
	scanf("%lf",&deg);
		rad=deg*(pai/180);
	printf("rad=%f\n",rad);
	
	return 0;
}