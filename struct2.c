#include<stdio.h>
#include<string.h>

typedef struct{
	int year; //�w�N
	int clas; //�N���X
	int number; //�o�Ȕԍ�
	char name[64]; //���O
	double stature; //�g��
	double weight; //�̏d
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
	
	student_print(&data); //�A�h���X�ŌĂяo��
	
	return 0;
}

void student_print(student *data)
{
	printf("�w�N:%d\n",data->year); //->�ŃA�N�Z�X
	printf("�N���X:%d\n",data->clas);
	printf("�o�Ȕԍ�:%d\n",data->number);
	printf("���O:%s\n",data->name);
	printf("�g��:%4.2f\n",data->stature);
	printf("�̏d:%4.2f\n",data->weight);
	
	return;
}
	