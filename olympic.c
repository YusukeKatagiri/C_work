#include<stdio.h>

int olympic(int year);


enum{
	olympic_non,
	olympic_summer,
	olympic_winter,
};

int main(void)
{
	int year,hold;
	
	scanf("%d",&year);
	hold=olympic(year);
	
	switch (hold){
	case olympic_non:
		printf("close\n");
		break;
	case olympic_summer:
		printf("summer olympic\n");
		break;
	case olympic_winter:
		printf("winter olympic\n");
		break;
	};
	
	return 0;
}

int olympic(int year)
{
	if (year%2==0){
		if(year%4==0){
			return olympic_summer;
		}else{
			return olympic_winter;
		}
	}else{
		return olympic_non;
	}
}