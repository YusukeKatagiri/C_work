//People.c

#inclede "People.h"

void InputPeople(People *data)
{
	
void InputPeople(People *data)
{
	printf("���O:");
	scanf("%s",data->name);
	printf("�N��:");
	scanf("%d",&data->age);
	printf("����(1-�j���A2-����):");
	scanf("%d",&data->sex);
	printf("\n");
}

void ShowPeople (People data)
{
	char sex[16];
	
	printf("���O:%s\n",data.name);
	printf("�N��:%d\n",data.age);
	
	if (data.sex == 1) {
		strcpy(sex,"�j��");
	} else {
		strcpy(sex,"����");
	}
	
	printf("����:%s\n",sex);
	printf("\n");
}