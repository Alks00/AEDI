#include <stdio.h>
#include <stdlib.h>

void incluir(*pBuffer){
	printf("Digite o nome da pessoa a ser adicionada:");
	scanf("%s",pBuffer);
}

void apagar(){

}

void buscar(){

}

void listar(){

}

void main(){

	void *pBuffer;
	int *op

    if((pBuffer = malloc(1*sizeof(char)))==NULL){
		printf("Memoria Insuficiente");
		exit(1);
	}

	printf("Selecione uma das opções:\n");
	printf("Incluir: 1\n");
	printf("Apagar : 2\n");
	printf("Buscar : 3\n");
	printf("Listar : 4\n");

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

	default:
	printf("Opção inválida!")
	}
	free(pBuffer);
}
