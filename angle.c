//angle.c
//deg‚©‚çrad‚Ö‚Ì•ÏŠ·

#include<stdio.h>
#include<math.h>

int main(void){
	
	double rad,deg;
	double pai=acos(-1.0);
	
	printf("Šp“x(deg)‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢Bdeg=");
	scanf("%lf",&deg);
		rad=deg*(pai/180);
	printf("rad=%f\n",rad);
	
	return 0;
}