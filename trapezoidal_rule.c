//��`����

#include<stdio.h>
#define X_MIN 0.0 // �ϕ��͈͂̍ŏ��l
#define X_MAX 100.0 //�ϕ��͈͂̍ő�l
#define DIV_NUM 120 //�ϕ��͈͂̕�����

//�ϕ��Ώۊ֐�
float function (float x)
{
float result;
result = x*x ;
return result;
}

int main()
{
double integral; //�ϕ�����
double h; //�ϕ��͈͂�n�ɕ��������Ƃ��̕�
double x,dA;
int i;

printf("�ϕ��͈�=[%f,%f] ������=%d\n", X_MIN,X_MAX,DIV_NUM);

// === ��`�����ɂ��ϕ�== //
h= (X_MAX-X_MIN)/DIV_NUM; //������
integral = 0.0; //�ϕ����ʂ̕ϐ���������
x=X_MIN; //�ϕ��͈͂̕ϐ���������
for (i=0;i<DIV_NUM;i++){
//�����͈̖͂ʐσ�A
dA=(function(x)+function(x+h))*h/2.0;
integral += dA; //��
x += h;
}
// ==��`�����ɂ��ϕ�(end)== //

printf("�ϕ�����=%lf\n", integral);
printf("��͓I�ɋ��߂�����(���100,����100�̒��p�O�p�`)=%lf\n", (X_MAX-X_MIN)*function(X_MAX)/2.0);

return(0);
}