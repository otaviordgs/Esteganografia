#include <stdlib.h>
#include <stdio.h>

#define WIDTH_OFFSET 0x0012
#define HEIGHT_OFFSET 0x0016

void pegarDimensoesImagem(FILE *imagem, int *largura, int *altura){
    // *altura = 10;
    // printf("O valor de altura antigo %d\n", *altura);   

    // // Moving pointer to start
    fseek(imagem, WIDTH_OFFSET, SEEK_SET);
    fread(largura, 4, 1, imagem);

    fseek(imagem, HEIGHT_OFFSET, SEEK_SET);
    fread(altura, 4, 1, imagem);

}


void lerImagem(char *filename){
    FILE *imagem = fopen(filename, "rb");
    int largura, altura, qtdBytesImagem;

    pegarDimensoesImagem(imagem, &largura, &altura);
    printf("A altura da imagem é  %d\n", altura);
    printf("A largura da imagem é  %d\n", largura);

    qtdBytesImagem = (largura * altura * 3) / 8;
}

int main(int args, char *argv[]){

    if (args < 3){
        printf("São necessários 2 argumentos! ( texto e imagem )\n");
        exit(-1);
    }

    char *texto, *imagem;  
    char continuar;

    printf("Levamos em conta que o primeiro argumento passado é o arquivo texto e o segundo a imagem \n");
    printf("Deseja continuar?(s/n)\n");
    scanf("%c", &continuar);

    if (continuar == 'n')
        exit(-1);
    
    texto = argv[1];
    imagem = argv[2];

    lerImagem(imagem);

    return 0;
}