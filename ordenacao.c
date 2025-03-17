#include <stdio.h>
#include <stdlib.h>
int main(){
	int arry[] = {11,7,5,10,2,1};
	int i;
	
	printf("Desordenado\n");
	for(i = 0; i < 6; i++){
		printf("posicao [%d]: conteudo [%d]\n", i,arry[i]);
	}
	
	
	for(i = 0; i < 6; i++){
		if(arry[i] > arry[i + 1]){
			int temp = arry[i];
			arry[i] = arry[i + 1];
			arry[i + 1]	= temp;
		}
	}
	printf("\nOrdenado\n");
	for(i = 0; i < 6; i++){
		printf("posicao [%d]: conteudo [%d]\n", i,arry[i]);
	}
	
	
	return 0;
}
