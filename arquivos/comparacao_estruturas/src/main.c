#include "avl.h"
#include "rbt.h"
#include "binaria.h"
#include "gera_aleatorio.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 10
#define MIL 1000
#define DEZ_MIL 10000
#define CEM_MIL 100000

void menu_avl();
void menu_rubro_negro();
void menu_binaria();

int main(){

	int op;

	system("clear || cls");

	do{
		printf("\n------MENU------\n\n");
		printf("Qual árvore deseja manusear? \n\n");

		printf("0 - Sair\n");
		printf("1 - árvore binária\n");
		printf("2 - árvore AVL\n");
		printf("3 - árvore Rubro Negra\n");
		scanf("%d", &op);
		switch(op){
			case 0:
				printf("Saindo...");
				break;
			case 1:
				printf("Árvore Binária");
				menu_binaria();
				break;
			case 2:
				printf("Árvore AVL");
				menu_avl();
				break;
			case 3:
				printf("Árvore Rubro Negra");
				menu_rubro_negro();
				break;
			default:
				printf("Escolha uma opção válida!\n");
				break;
		}
	}while(op != 0);

	printf("Fim...");

	return 0;
}

void menu_avl(){

	system("cls || clear");
	
	Tree_avl *raiz = avl_CreateTree();
	Tree_avl *aux = avl_CreateTree();
	Record_avl r;
	int num;
	clock_t t; //variável para armazenar o tempo

	printf("\nÁrvore AVL em C\n\n");
	printf("autor: Leonardo Campos\n");
	
	do{
	    printf("Escolha uma opção: \n");
	    printf("0 - sair\n");
	    printf("1 - inserir valor\n");
	    printf("2 - remover\n");
	    printf("3 - imprimir árvore\n");
	    printf("4 - limpar tela\n");
	    scanf("%d", &num);
	    switch(num){
	        case 0:
	            printf("\nSaindo...\n");
	            break;
	        case 1:
	            printf("\nDigite um valor: ");
	            scanf("%d", &num);
	            t=clock();
	            r.key = num;
	            r.value = 1;
	            avl_insertTree(&raiz, r);
	            t=clock() - t;
	            printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	            break;
	        case 2:
	            printf("\nDigite um número para remover: \n");
	            t=clock();
	            scanf("%d", &num);
	            r.key = num;
	            avl_removeTree(&raiz, &raiz, r);
	            t=clock() - t;
	            printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	            break;
	        case 3:
	            printf("\nÁrvore\n");
	            t=clock();
	            printf("[");
	            avl_central(raiz);
	            printf("fim]");
	            t=clock() - t;
	            printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	            printf("\n");
	            break;
	        case 4:
	           	system("cls || clear");
	        default:
	            printf("\nEscolha uma opção válida!\n");
	            break;
	    }
	}while(num);
}

void menu_rubro_negro() {
    TNoRB *arvore = NULL;
    clock_t t; //variável para armazenar o tempo
    int opc = -1, flag = 1, n, rn;
    

    do {
        printf("1 - Inserir elemento;\n2 - Remover elemento;\n3 - Ver árvore;\n4 - Sair\n");
        scanf("%d", &opc);

        switch(opc) {
            case 1:
                printf("Elemento a inserir:\n");
                t=clock();
                scanf("%d", &n);
                insereNo(&arvore, NULL, &arvore, n);
                t=clock() - t;
                printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
                break;

            case 2:
                printf("Elemento a remover:\n");
                t=clock();
                scanf("%d", &rn);
                removeNo(&arvore, rn);
                t=clock() - t;
                printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
                break;

            case 3:
            	t=clock();
                inOrder(arvore);
                t=clock() - t;
                printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
                break;

            case 4:
                flag = 0;
                break;

            default:
                printf("Opção inválida.\n");
        }

        printf("==========\n");
    } while (flag);
}

void menu_binaria(){

	system("clear || cls");

	int reg[MIL] = {};
	Tree *raiz = CreateTree();
	Tree *aux = CreateTree();
	Record r;
	clock_t t; //variável para armazenar o tempo
	int esc;

	printf("\nMENU\n\n");
	printf("Escolha qual inserção irá medir primeiro:\n");
	printf("1 - 1000 entradas\n");
	printf("2 - 10.000 entradas\n");
	printf("3 - 100.000 entradas\n");
	scanf("%d",&esc);

	switch(esc) {
		case 1:
			t=clock();
			printf("\nPreenchendo matriz...\n");
			for(int i=0; i<MIL ; i++){
				reg[i]= rand() % MIL;
			}
			t=clock() - t;
		    printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

			printf("ELEMENTOS DA ARVORE: { ");
		  	for(int i=0; i<MIL; i++){
				r.key = reg[i];
				r.value = 1;
				insertTree(&raiz, r);
		    printf("%d ", reg[i]);
			}
		  	printf("}\n\n");

			//printf("METODO PREORDEM: { ");
		  	//preordem(raiz);
		  	//printf("}\n\n");

			t=clock();
		  	printf("METODO CENTRAL: { ");
		  	central(raiz);
			printf("}\n\n");
			t=clock() - t;
		    printf("Tempo de execucao de busca: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

		  	//printf("METODO POSORDEM: { ");
		  	//posordem(raiz);
		  	//printf("}\n\n");
			break;
		case 2:
			t=clock();
			printf("\nPreenchendo matriz...\n");
			for(int i=0; i<DEZ_MIL ; i++){
				reg[i]= rand() % MIL;
			}
			t=clock() - t;
		    printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

			printf("ELEMENTOS DA ARVORE: { ");
		  	for(int i=0; i<DEZ_MIL; i++){
				r.key = reg[i];
				r.value = 1;
				insertTree(&raiz, r);
		    printf("%d ", reg[i]);
			}
		  	printf("}\n\n");

			//printf("METODO PREORDEM: { ");
		  	//preordem(raiz);
		  	//printf("}\n\n");

			t=clock();
		  	printf("METODO CENTRAL: { ");
		  	central(raiz);
			printf("}\n\n");
			t=clock() - t;
		    printf("Tempo de execucao de busca: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

		  	//printf("METODO POSORDEM: { ");
		  	//posordem(raiz);
		  	//printf("}\n\n");
			break;
		case 3:
			t=clock();
			printf("\nPreenchendo matriz...\n");
			for(int i=0; i<CEM_MIL ; i++){
				reg[i]= rand() % MIL;
			}
			t=clock() - t;
		    printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

			printf("ELEMENTOS DA ARVORE: { ");
		  	for(int i=0; i<CEM_MIL; i++){
				r.key = reg[i];
				r.value = 1;
				insertTree(&raiz, r);
		    printf("%d ", reg[i]);
			}
		  	printf("}\n\n");

			//printf("METODO PREORDEM: { ");
		  	//preordem(raiz);
		  	//printf("}\n\n");

			t=clock();
		  	printf("METODO CENTRAL: { ");
		  	central(raiz);
			printf("}\n\n");
			t=clock() - t;
		    printf("Tempo de execucao de busca: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

		  	//printf("METODO POSORDEM: { ");
		  	//posordem(raiz);
		  	//printf("}\n\n");
			break;
		default:
			printf("Escolha uma opção válida!");
			break;
	}
}