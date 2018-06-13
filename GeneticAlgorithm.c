#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Individual.c"
#define WEIGHT1 14416	
#define WEIGHT2 26212
#define WEIGHT3 42598
#define WEIGHT4 65535

struct GeneticAlgorithm
{
	int Generaciones;
	struct Individual listPopulation[];
};

void createPopulation(int start ,int quantity, int from, int until, struct Individual pPopulation[])
{
	srand(time(NULL)); 
	for (int indexIndividuo = start; indexIndividuo < quantity+start; indexIndividuo++)
	{
		struct Individual individuo;
		pPopulation[indexIndividuo] = individuo;
		int num = rand() % until + from;
		pPopulation[indexIndividuo].phenotype = num;
	}
}


void create(int p1, int p2, int p3, int p4, struct Individual pPopulation[]){
	createPopulation(0, p1, 0, WEIGHT1, pPopulation);
	createPopulation(p1, p2, WEIGHT1, WEIGHT2, pPopulation);
	createPopulation(p1+p2, p3, WEIGHT2, WEIGHT3, pPopulation);
	createPopulation(p1+p2+p3, p4, WEIGHT3, WEIGHT4, pPopulation);
}

char * decToBin(int decimal)
{
	int tempDecimal;  
	char * binary = (char *)(malloc(16));  
	int index = 0;  
	
	tempDecimal = decimal;  

	while(tempDecimal!=0)  
	{  
		binary[index] = (tempDecimal % 2) + '0';  
		tempDecimal /= 2;  
		index++;  
	}  
	binary[index] = '\0';  
	strrev(binary);
	return binary;  
}

int averagePopulation(struct Individual plistPopulation[], int range){
	for (int indexIndividuo = 0; indexIndividuo < range; indexIndividuo++){
		if (plistPopulation[indexIndividuo].phenotype > range);
	}
	return 0;
	
}

void fitnessFunction(struct Individual plistPopulation[], int range, int pSize){
	for (int indexIndividuo = 0; indexIndividuo < pSize; indexIndividuo++){
		//int average = averagePopulation(plistPopulation, pPopulation[indexIndividuo].phenotype, range);
	} 
}

int binToDec(const char *bin) 
{
    int i, j;
    j = sizeof(int)*8;
    while ( (j--) && ((*bin=='0') || (*bin=='1')) ) {
        i <<= 1;
        if ( *bin=='1' ) i++;
        bin++;
    }
    return i;
}

void print(struct Individual pPopulation[], int pSize)
{
	for (int indexIndividuo = 0; indexIndividuo < pSize; indexIndividuo++){
		printf("%d\n", pPopulation[indexIndividuo].phenotype);
	}
}

void printBin(struct Individual pPopulation[], int pSize)
{
	for (int indexIndividuo = 0; indexIndividuo < pSize; indexIndividuo++){
		printf("%s\n", pPopulation[indexIndividuo].genome);
	}
}


void calculateBin(struct Individual pPopulation[], int pSize)
{
	for (int indexIndividuo = 0; indexIndividuo < pSize; indexIndividuo++){
		char * n = decToBin(pPopulation[indexIndividuo].phenotype);
		printf("%s\n", n );
	}
}

int sizeOfList(struct Individual pPopulation[])
{
	int indexIndividuo = 0;
	while(pPopulation[indexIndividuo].phenotype != 0){
		indexIndividuo++;
	}
	return indexIndividuo;
}

void qs(struct Individual lista[], int limite_izq,int limite_der)
{
	struct Individual temporal;
	int izq,der,pivote;
	izq=limite_izq;
	der = limite_der;
	pivote = lista[(izq+der)/2].phenotype;
	do{
		while(lista[izq].phenotype<pivote && izq<limite_der)izq++;
		while(pivote<lista[der].phenotype && der > limite_izq)der--;
		if(izq <=der)
		{
			temporal= lista[izq];
			lista[izq]=lista[der];
			lista[der]=temporal;
			izq++;
			der--;
 	   	}
 	}while(izq<=der);
	if(limite_izq<der){qs(lista,limite_izq,der);}
	if(limite_der>izq){qs(lista,izq,limite_der);}
}

void quicksort(struct Individual lista[],int n)
{
    qs(lista,0,n-1);
}