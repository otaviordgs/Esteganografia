#include <stdlib.h>
#include <stdio.h>

int main(int args, char *argv[]){

    if (args < 3)
        exit(-1);

    char *texto, *imagem;  
    char continuar;

    printf("Levamos em conta que o primeiro argumento passado é o arquivo texto e o segundo a imagem \n");
    printf("Deseja continuar?(s/n)\n");
    scanf("%c", &continuar);

    if (continuar == 'n')
        exit(-1);
    
    

    return 0;
}