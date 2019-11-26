#include <pthread.h>
#include <stdio.h>

#define WORKERS 3
#define NUM_LINES 300
#define NUM_COLS 300
//Multiplica duas matrizes 300x300

struct ARGS{
	int id;
	long initialLine;
};


typedef struct ARGS THREAD_ARG;



int A[NUM_LINES][NUM_COLS],B[NUM_LINES][NUM_COLS],C[NUM_LINES][NUM_COLS];

void* mult(void* args){
	THREAD_ARG *local = (THREAD_ARG *)args;
	int aux=0;

	int i = local->initialLine;
	
	printf("worker %d: begin computation\n",local->id);

	for(; i < local->initialLine + NUM_LINES/WORKERS; i++){		
		for(int j = 0; j < NUM_COLS; j++){             
             for(int x = 0; x < NUM_LINES; x+=4){ 	//Fazendo loop unrolling
             	aux += A[i][x] * B[x][j];
             	aux += A[i][x+1] * B[x+1][j];
             	aux += A[i][x+2] * B[x+2][j];
             	aux += A[i][x+3] * B[x+3][j];
             }
             C[i][j] = aux;             
             aux = 0;             
     	}     	
     }		
     printf("worker %d has ended its computation\n",local->id);
}

void* init(void* args){
	THREAD_ARG *local = (THREAD_ARG *)args;
	int aux=0;

	int i = local->initialLine;
	printf("worker %d: init matrix lines [%d,%d)\n",local->id,i,i+NUM_LINES/WORKERS);
	for(; i < local->initialLine + NUM_LINES/WORKERS; i++){		
		for(int j = 0; j < NUM_COLS; j++){             
             A[i][j] = i*j;
             B[i][j] = i*j;
     	}     	
     }
     printf("worker %d: finish init\n",local->id);
}


int main(){
	/* this variable is our reference to the second thread */
	pthread_t thread[WORKERS];	
	THREAD_ARG n[WORKERS];
	int i;

	for(int i = 0; i < WORKERS; i++){
		n[i].id = i;
		n[i].initialLine = i*(NUM_LINES/WORKERS);
	}
	//Cria workers para inicializar matriz a e b
	//Cria workers para multiplicar as matrizes
	for(i = 0; i < WORKERS; i++){
		if(pthread_create(&thread[i], NULL, init, &n[i])) {
			fprintf(stderr, "Error creating thread %d\n",i);
			return 1;
		}
	}

	//Sincroniza para poder comecaq a multiplicacao
	for(i = 0; i < WORKERS; i++){	//Espera o fim das tarefas das threads
		pthread_join(thread[i], NULL);
	}

	//Cria workers para multiplicar as matrizes
	for(i = 0; i < WORKERS; i++){
		if(pthread_create(&thread[i], NULL, mult, &n[i])) {
			fprintf(stderr, "Error creating thread %d\n",i);
			return 1;
		}
	}

	for(i = 0; i < WORKERS; i++){	//Espera o fim das tarefas das threads
		pthread_join(thread[i], NULL);
	}

	
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			printf("%11d ",C[i][j]);
		}
		printf("\n");		
	}


	return 0;
}
