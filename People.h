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

//個人データ入力
extern void InputPeople(People *data);

//個人データ表示
extern void ShowPeople(People data);

#endif