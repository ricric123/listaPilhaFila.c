#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 5

//global
int pilha[TAM];
int topo=-1;

//protótipos
void push(int x);
int pop();
int peek();

//push: empilhar: inserir elemento no topo da pilha,
//se houver capacidade
void push(int x){
	if(topo==TAM-1){
		printf("Pilha cheia.\n");
	}else{
		topo++;
		pilha[topo]=x;
	}	
}


//peek: consultar: retornar o elemento do topo da pilha
//se houver elementos na pilha
//senão retornar -1
int peek(){
	if(topo==-1){
		printf("Pilha vazia.\n");
		return -1;
	}else{
		return pilha[topo];
	}
}

//pop: remover: retirar e retornar o elemento do topo da pilha
//se houver elementos na pilha
//senão, retornar -1
int pop(){
	if(topo==-1){
		printf("Pilha vazia.\n");
		return -1;
	}else{
		topo--;
		return pilha[topo+1];
	}
}


//mostrar pilha na vertical
void mostraPilha(){
	int i;
	for(i=topo;i>=0;i--){
		printf("%d\n", pilha[i]);
	}
	printf("\n");
}

main(){
	setlocale(LC_ALL, "");
	//variáveis locais
	int op, n;
	
	
	do{
		// apresentar as opções do menu
		system("cls");
		printf("# Pilha #\n\n");
		printf("1-Push\n");
		printf("2-Pop\n");
		printf("3-Peek\n");
		printf("4-Listar\n");
		printf("5-Sair\n\n");
		printf("Opção: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:		
				printf("Informe o numero a ser empilhado:");
				scanf("%d", &n);
				push(n);
				break;
			case 2:
				n=pop();
				if(n!=-1){
					printf("Elemento removido: %d\n", n);
				}
				break;
			case 3:
				n=peek();
				if(n!=-1){
					printf("Elemento do topo: %d\n", n);
				}
				printf("%d", pilha[topo]);
				break;
			case 4:
				mostraPilha();
				break;
			case 5:
				break;
			default:
				printf("Opção invalida. Tente novamente.\n\n");							
		}
		
		getch();
		
	}while(op!=5);
}
