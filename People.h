//People.h
#ifndef __PEOPLE_H__
#define __PEOPLE_H_

#include<stdio.h>
#include<string.h>

typefdef struct {
	char name[256];
	int age;
	int sex;
}PEOPLE;

//�l�f�[�^����
extern void InputPeople(People *data);

//�l�f�[�^�\��
extern void ShowPeople(People data);

#endif