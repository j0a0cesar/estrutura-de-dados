#include <stdio.h>
int fatorial(int num){
	if( num == 1){
		return 1;
	}else{
		return (num* fatorial(num - 1));
	}
}
int main(){
	int num;
	printf("Digite o numero que quer saber o fatorial: ");
	scanf("%d",&num);
	printf("o fatorial de %d eh %d", num, fatorial(num));
return 0;	
}
