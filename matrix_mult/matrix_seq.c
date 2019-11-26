
#include <stdio.h>

#define NUM_LINES 300
#define NUM_COLS 300
//Multiplica duas matrizes 300x300



int A[NUM_LINES][NUM_COLS],B[NUM_LINES][NUM_COLS],C[NUM_LINES][NUM_COLS];

void mult(){
	int aux=0;
	
	for(int i = 0; i <  NUM_LINES; i++){		
		for(int j = 0; j < NUM_COLS; j++){             
             for(int x = 0; x < NUM_LINES; x++){ 	//Fazendo loop unrolling
             	aux += A[i][x] * B[x][j];
             }
             C[i][j] = aux;             
             aux = 0;             
     	}     	
     }	
     
}

void init(){	
	for(int i = 0; i < NUM_LINES; i++){		
		for(int j = 0; j < NUM_COLS; j++){             
             A[i][j] = i*j;
             B[i][j] = i*j;
     	}     	
     }     
}


int main(){	
	init();
	mult();	
	
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			printf("%11d ",C[i][j]);
		}
		printf("\n");		
	}

	return 0;
}
