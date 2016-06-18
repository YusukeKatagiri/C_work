/*文字列の連結*/
//#include<stdio.h>
//int main(void)
//{
//	char str[]="DRAGON""QUEST";
//	printf("%s\n",str);
//	return 0;
//}

/*strcatを使った文字列の連結*/
//#include<stdio.h>
//#include<string.h>
//int main(void)
//{
//	char str1[12]="DRAGON";
//	char str2[]="QUEST";
//	strcat(str1,str2);
//	printf("%s\n",str1);
//	return 0;
//}

/*sprintfを用いた文字列連結*/
//#include<stdio.h>
//
//int main(void)
//{
//	char str[16];
//	char str1[12]="DRAGON";
//	char str2[]="QUEST";
//	int i=3;
//	sprintf(str,"%s%s%d\n",str1,str2,i);
//	printf("%s\n",str);
//	return 0;
//}

/*文字列の入力*/
//#include<stdio.h>
//int main(void)
//{
//	char str[32];
//	scanf("%s",str);
//	printf("%s\n",str);
//	return 0;
//}

/*文字数カウント*/
//#include<stdio.h>
//int main(void)
//{
//	int i;
//	
//	char str[256];
//	scanf("%s",str);
//	
//	for(i=0;str[i]!='\0';i++);
//	
//	printf("%d\n",i);
//	
//	return 0;
//}

/*strlenを用いた文字数カウント*/
//#include<stdio.h>
//#include<string.h>
//
//int main(void)
//{
//	int i;
//	
//	char str[256];
//	scanf("%s",str);
//	
//	i=strlen(str);
//	
//	printf("%d\n",i);
//	
//	return 0;
//}

/*strcmpを用いた文字列比較*/
#include<stdio.h>
#include<string.h>
int main(void)
{
	char str1[256],str2[]="dragonquest";
	
	scanf("%s",str1);
	
	if(strcmp(str1,str2)==0){
		printf("同じ\n");
	}else{
		printf("違う\n");
	}
	return 0;
}

