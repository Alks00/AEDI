#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *pBuffer;

typedef struct Pessoa{
    char nome[20];
}pessoa;

typedef struct variavel{
    int op,i,j,cont,a,min_id;
    pessoa atual,min;
}variaveis;

void incluir(variaveis* aux, pessoa* nome){
	if((pBuffer=realloc(pBuffer,sizeof(variaveis)+sizeof(pessoa)+(aux->cont * sizeof(pessoa))))==NULL){
        printf("Nao foi possivel alocar memoria");
        exit(1);
	}
	aux = pBuffer;
	nome = pBuffer + sizeof(variaveis) + (aux->cont * sizeof(pessoa));

	printf("Escreva um nome:\n");
	getchar();
	fgets(nome->nome,20,stdin);

	aux->cont++;
}

void apagar(variaveis* aux){
    if(aux->cont>0){
        if((pBuffer=realloc(pBuffer,sizeof(variaveis)+sizeof(pessoa)+(aux->cont-1 * sizeof(pessoa))))==NULL){
            printf("Nao foi possivel alocar memoria");
            exit(1);
        }
    }else{
        printf("Nao ha mais nomes para serem apagados!");
    }
	aux->cont--;
}

void buscar(variaveis* aux){
    pessoa  *buscar,*nome;

    nome = pBuffer + sizeof(variaveis);

    if((buscar = (pessoa *)calloc(1,sizeof(pessoa)))== NULL){
        printf("Memoria Insuficiente");
        exit(1);
    }

    printf("Digite o nome:\n");
    scanf("%s",buscar->nome);
    printf("\n");

    for(aux->i = 0; aux->i < aux->cont; aux->i++){
		if((strcmp(buscar->nome,nome->nome))== 0){
			printf("%s\n",nome->nome);
			nome++;
			aux->a++;
		}
		else
			nome++;
	}

	if(aux->a == 0){
        printf("O nome nao existe na agenda\n");
	}
	printf("\n");

	aux->a = 0;

	free(buscar);
}

void listar(variaveis *aux){
    pessoa *nome;
    nome = pBuffer + sizeof(variaveis);
    for(aux->i=0;aux->i<aux->cont;aux->i++){
        printf("%s",nome->nome);
        nome++;
    }
}

void insertionSort(variaveis* aux){
    pessoa *original;
    original = pBuffer + sizeof(variaveis);

    if(aux->cont > 1){
        for (aux->i = 1; aux->i < aux->cont; aux->i++) {
            aux->atual = original[aux->i];
            for (aux->j = aux->i - 1; (aux->j >= 0) && (aux->atual.nome[0] < original[aux->j].nome[0]); aux->j--) {
                original[aux->j + 1] = original[aux->j];
            }
            original[aux->j+1] = aux->atual;
        }
    }
}

void selectionSort(variaveis* aux){
    pessoa  *nome
    nome = pBuffer + sizeof(variaveis);

    for (aux->i = 0; aux->i < aux->cont-1; aux->i++) {
        aux->min = nome[aux->i];
        for (aux->j = (aux->i+1); aux->j < aux->cont; aux->j++) {
            if(nome[aux->j].nome[0] < aux->min.nome[0]){
                aux->min = nome[aux->j];
                aux->min_id = aux->j;
            }
        }

    }
}


void sort(variaveis *aux){
    insertionSort(aux);
    //selectionSort(aux);
    //bubbleSort(aux);
    //quickSort(aux);

}

void main(){

    variaveis *aux;
    pessoa *nome;

    if((pBuffer =(variaveis *) malloc(sizeof(variaveis)))==NULL){
		printf("Memoria Insuficiente");
		exit(1);
	}

	aux = pBuffer;
	aux->cont = 0;
    do{
        printf("Selecione uma das opcoes:\n");
        printf("Incluir: 1\n");
        printf("Apagar : 2\n");
        printf("Buscar : 3\n");
        printf("Listar : 4\n");
        printf("Ordenar: 5\n");
        printf("Sair   : 6\n");

        scanf("%d", &aux->op);


        switch (aux->op){

        case 1:
        incluir(aux,nome);
        break;

        case 2:
        apagar(aux);
        break;

        case 3:
        buscar(aux);
        break;

        case 4:
        listar(aux);
        break;

        case 5:
        sort(aux);
        break;

        case 6:
        break;

        default:
        printf("Opcao invalida!\n");
        break;
        }
    }while(aux->op != 6);

	free(pBuffer);
}
