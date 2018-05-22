#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int indice;
	//char direccion[] = "C:\\Users\\Administrator\\Documents\\Segunda Progra Bases.txt";
	char direccion[] = "C:\\Users\\Administrator\\Downloads\\TareaCorta\\src\\Logica\\Bingo.java";

	FILE *archivo = fopen(direccion, "rt");

	if (archivo == NULL){
		printf("Error");
		return 1;
	}

	while((indice = fgetc(archivo)) != EOF){
		if (indice == '\n' || indice == ' '){
			printf("\n");
		}
		else if (indice != '\t'){
			putchar(indice);
		}
	}

	fclose(archivo);

	return 0;
}
