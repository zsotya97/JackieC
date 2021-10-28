#pragma once
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
typedef struct Jackie
{
	int year;
	int races;
	int wins;
	int podium;
	int poles;
	int fastests;


}Jackie;
typedef struct Adatok
{

	struct Adatok* kov;
	Jackie adat;

}Adatok;
Adatok* add(Adatok* adat, Jackie beolvasott);
void torles(Adatok* elso);



Adatok* add(Adatok* adat, Jackie beolvasott)
{
	Adatok* temp;
	temp = (Adatok*)malloc(sizeof(Adatok));
	temp->adat = *(Jackie*)&beolvasott;
	temp->kov = NULL;
	adat->kov = temp;
	return temp;

}
void torles(Adatok* elso)
{
	Adatok* elem, * temp;
	elem = elso;
	while (elem != NULL)
	{
		temp = elem;
		elem = elem->kov;
		free(temp);
	}
}
