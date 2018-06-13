#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "FileReader.c"

char * separateFileNames(char pNames[]){
    char * files;
    files = strtok(pNames, " ");
    return files;
};

void printNames(char * pString){
    while (pString != NULL) {
        printf("%s\n", pString);
        pString = strtok(NULL, "");
    }
    getch();    
};

char * concatenate(char * pChar1, char * pChar2){
    char * result;
    result = malloc(strlen(pChar1) + strlen(pChar2)+2);
    strcpy(result, pChar1);
    strcat(result, pChar2);
    return result;
};

char * loadFiles(char pParams[]){
    char * directory = "C:\\Users\\Administrator\\Downloads\\TareaCorta\\src\\Logica\\";

    char * fileNames; //Donde guarda las direcciones separadas
    char * content = "";  //Donde guarda todo el contenido
    fileNames = separateFileNames(pParams);

    //Carga uno por uno el contenido en content
    while(fileNames != NULL){
        char * fileDirection = concatenate(directory, fileNames); //Direccion + nombre
        char * fileContent = readArchive(fileDirection); //Lee el archivo       
        content = concatenate(content, fileContent); //Lo concantena al contenido
        fileNames = strtok(NULL, " ");
        fileDirection = directory; //Resetea la direccion
    }
    getch();
    return content;
};