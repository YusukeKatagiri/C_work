/*10番目のアルファベットを取り出す*/
//#include<stdio.h>
//int main(void)
//{
//	char c='A'+9; /*最初は0なので9を足す*/
//	printf("%c\n",c);
//	return 0;
//}

/*数字を数値に変換*/
//#include<stdio.h>
//int main(void)
//{
//	char c= '8'; /*数字*/
//	int suuti = c-'0'; /*数値に変換*/
//	printf("%d\n",suuti);
//	return 0;
//}

/*変換する文字が数字かどうか判定*/
#include<stdio.h>
int main(void)
{
	char c='6'; /*数字*/
	int suuti;
	if (c>='0' && c<='9'){ /*判定部分*/
		suuti = c-'0'; /*数値に変換*/
	}else{
		suuti=0;
	}
	printf("%d\n",suuti);
	return 0;
}
