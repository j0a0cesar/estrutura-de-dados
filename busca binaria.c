#include <stdio.h>
#include <stdlib.h>
//codigo explicando busca binaria
int main(){
	//como é busca binaria a lista, precisa estar ordenada
	int lista[] = {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29};
	int alto = 14, baixo = 0, meio,chute,item;
	
	
	printf("Digite que numero deseja buscar: ");
	scanf("%d",&item);
	
	while (baixo <= alto){
		
		meio = (alto + baixo)/2; //pra encontrar o indice do meio da lista
		chute = lista[meio];     //pega o valor nesse índice e o armazena na variável chute, que é então comparada com o valor que estamos buscando.
		
	
	if(chute == item){
		item = chute;
		printf("Elemento %d, Encontrado na posicao %d", item,meio);
		return 0;
	}
	if( chute > item){
		alto = meio -1;
		
	}
	else{
		baixo = meio + 1;
	}
		
	}

	printf("Elemento %d nao encontrado", item);
	
return 0;
}
