#include <stdio.h>
#include <stdlib.h>
#include "FileReader.c"
#include "GeneticAlgorithm.c"
#include <math.h>
#include "time.h"
#include <windows.h>


int main(void) {
	
	
	printf("%s", "Digite el nombre de los archivos: ");
	char names[1000];
	scanf("%[^\n]s",names);
	printf("%s",names);
	//char s[] = "AcomodarPersonas.txt Backtracking.txt Probabilistic.txt jugadores.txt";
	char * content = loadFiles(names);
	printNames(content);
	

	struct GeneticAlgorithm population;
	create(3,4,3,2, population.listPopulation);
	print(population.listPopulation, sizeOfList(population.listPopulation));
	calculateBin(population.listPopulation, sizeOfList(population.listPopulation));
	printBin(population.listPopulation, sizeOfList(population.listPopulation));

   	return 0;
}
