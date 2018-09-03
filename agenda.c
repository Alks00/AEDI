#include <stdio.h>
#include <stdlib.h>

typedef struct contato{
    char nome[20];
    int numero;
    struct contato *proxContato;
}Contato

void incluir(*pBuffer){
	pBuffer = (Contato *)realloc(pBuffer,1*sizeof(Contato));

	printf("Digite o nome da pessoa a ser adicionada:");
	scanf("%s",pBuffer);

	printf("Digite o número da pessoa a ser adicionada:");
	scanf("%d",pBuffer);
}

void apagar(){

}

void buscar(){

}

void listar(){

}

void Sair(){
    free(pBuffer);
}

void main(){

	void *pBuffer;
	int *op

    if((pBuffer = malloc(1*sizeof(int)))==NULL){
		printf("Memoria Insuficiente");
		exit(1);
	}

    while(1>0){
        printf("Selecione uma das opções:\n");
        printf("Incluir: 1\n");
        printf("Apagar : 2\n");
        printf("Buscar : 3\n");
        printf("Listar : 4\n");
        printf("Sair   : 5\n");

        scanf("%d",op);

        switch (op){
        case 1 :
        incluir(pBuffer);
        break;

        case 2:
        apagar();
        break;

        case 3:
        buscar();
        break;

        case 4:
        listar();
        break;

        case 5:
        Sair(pBuffer);
        break;

        default:
        printf("Opção inválida!")
        }
    }
}
