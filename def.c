#include<stdio.h>
#define EXCISETAX 0.08 //�萔�錾

int main(void)
{
	int price;
	printf("�{�̉��i:");
	scanf("%d",&price);
	
	price=(int)((1+EXCISETAX)*price); //�萔�g�p
	printf("�ō����i:%d\n",price);
	
	return 0;
}