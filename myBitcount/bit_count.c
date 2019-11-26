#include <pthread.h>
#include <stdio.h>

#define WORKERS 3
#define ITERACTIONS 75000
/*
**  Bit counter by Ratko Tomic
*   Optimized 1 bit/loop counter
*   Esta versão é a input small, com 75000 interações
*/
struct ARGS{
	int id;
	long initialValue;
	long resultado;
};

typedef struct ARGS THREAD_ARG;

void* bit_count(void* x){
		THREAD_ARG *local = (THREAD_ARG *)x;
		
		local->resultado = 0;
		int i = local->initialValue;

		long seed = i*13 + 112500;

		printf("Worker %d: from %ld to %ld\n",local->id,local->initialValue,local->initialValue+ITERACTIONS/WORKERS);

		for(; i < local->initialValue+ITERACTIONS/WORKERS; i++,seed+=13){
        	long x;
        	x = seed;
        	if (x) do
              local->resultado++;
        	while (0 != (x = x&(x-1))) ;
        }        
}



int main(){
	/* this variable is our reference to the second thread */
	pthread_t thread[WORKERS];	
	THREAD_ARG n[WORKERS];
	int i;

	for(int i = 0; i < WORKERS; i++){
		n[i].id = i;
		n[i].initialValue = i*(ITERACTIONS/WORKERS);
	}

	for(i = 0; i < WORKERS; i++){
		if(pthread_create(&thread[i], NULL, bit_count, &n[i])) {
			fprintf(stderr, "Error creating thread %d\n",i);
			return 1;
		}
	}

	for(i = 0; i < WORKERS; i++){	//Espera o fim das tarefas das threads
		pthread_join(thread[i], NULL);
	}

	long resultado = n[0].resultado;
	for(int i = 1; i < WORKERS; i++){
		resultado += n[i].resultado;
	}

	for(i = 0; i < WORKERS; i++){
		printf("resultado core %d:  %ld\n",i,n[i].resultado);
	}	
	printf("res: %ld\n",resultado);

	return 0;
}
