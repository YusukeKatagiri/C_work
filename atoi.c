/*数値への変換*/
//#include<stdio.h>
//#include<stdlib.h>
//
//int main(void)
//{
//	char str[]="145";
//	int suuti = atoi(str);
//	printf("%d\n",suuti);
//	return 0;
//}

/*文字列のコピー*/
#include<stdio.h>
#include<string.h>

int main(void)
{
	char str[10];
	strcpy(str,"MARIO");
	printf("%s\n",str);
	return 0;
}

