#include<stdio.h>

struct student {
	int year; //�w�N
	int clas; //�N���X
	int number; //�o�Ȕԍ�
	char name[64]; //���O
	double stature; //�g��
	double weight; //�̏d
};

int main(void)
{
	struct student data;
	
	data.year = 10;
	printf("%d\n",data.year);
	
	return 0;
}
