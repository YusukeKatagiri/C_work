#include<stdio.h>
#include<string.h>

typedef struct{
	char name[256]; //���O
	int age; //�N��
	int sex; //����
} People;

void InputPeople(People *data);
void ShowPeople(People data);

int main(void)
{
	People data[3];
	int i;
	
	for (i=0;i<3;i++){
		InputPeople(&data[i]);
	}
	
	for (i=0;i<3;i++){
		ShowPeople(data[i]);
	}
	
	return 0;
}

void InputPeople(People *data)
{
	printf("���O:");
	scanf("%s",data->name);
	printf("�N��:");
	scanf("%d",&data->age);
	printf("����(1-�j��, 2-����):");
	scanf("%d",&data->sex);
	printf("\n");
}

void ShowPeople(People data)
{
	char sex[16];
	
	printf("���O:%s\n",data.name);
	printf("�N��:%d\n",data.age);
	
	if (data.sex==1){
		strcpy(sex,"�j��");
	}else{
		strcpy(sex,"����");
	}
	
	printf("����:%s\n",sex);
	printf("\n");
}
