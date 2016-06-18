#include<stdio.h>
#include<string.h>

typedef struct{
	int year; //学年
	int clas; //クラス
	int number; //出席番号
	char name[64]; //名前
	double stature; //身長
	double weight; //体重
} student;

void student_print(student *data);

int main(void)
{
	student data;
	
	data.year = 10;
	data.clas=4;
	data.number=18;
	strcpy(data.name,"MARIO");
	data.stature=168.2;
	data.weight=72.4;
	
	student_print(&data); //アドレスで呼び出す
	
	return 0;
}

void student_print(student *data)
{
	printf("学年:%d\n",data->year); //->でアクセス
	printf("クラス:%d\n",data->clas);
	printf("出席番号:%d\n",data->number);
	printf("名前:%s\n",data->name);
	printf("身長:%4.2f\n",data->stature);
	printf("体重:%4.2f\n",data->weight);
	
	return;
}
	