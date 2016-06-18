#include<stdio.h>

struct student {
	int year; //学年
	int clas; //クラス
	int number; //出席番号
	char name[64]; //名前
	double stature; //身長
	double weight; //体重
};

int main(void)
{
	struct student data;
	
	data.year = 10;
	printf("%d\n",data.year);
	
	return 0;
}
