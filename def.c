#include<stdio.h>
#define EXCISETAX 0.08 //’è”éŒ¾

int main(void)
{
	int price;
	printf("–{‘Ì‰¿Ši:");
	scanf("%d",&price);
	
	price=(int)((1+EXCISETAX)*price); //’è”g—p
	printf("Å‰¿Ši:%d\n",price);
	
	return 0;
}