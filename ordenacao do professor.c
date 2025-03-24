#include <stdio.h>
int main(){
	int arry[8] = {3,8,7,8,1,2,3,2};
	int i,j,idMaior = 0,temp = 0;
	for(i = 0; i < 8; i++){
		idMaior = i;
		for(j = i+1;j < 8;j++){
			if(arry[i] < arry[j]){
				idMaior = j;
			}
		}
	}
	temp = arry[i];
	arry[i] = arry[idMaior];
	arry[idMaior] = temp;
	
	for(i =0; i < 8; i++){
		printf("[%d]: [%d]\n",i,arry[i]);
	}
return 0;	
}
