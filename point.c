/*ポインタの確認*/
//#include<stdio.h>
//
//int main(void)
//{
//	int *p,i;
//	p=&i;
//	printf("p=%p\n",p);
//	printf("&i=%p\n",&i);
//	return 0;
//}

/*モードの切り替え*/
#include<stdio.h>

int main(void)
{
	int *p,i;	
	p=i;
	*p=10; /*通常変数モードに切り替えたポインタ変数に代入*/
	printf("*p=%d\n",*p);
	printf("i=%d\n",i);
	return 0;
}

