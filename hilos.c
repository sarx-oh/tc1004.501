#include <stdio.h>
#include <pthread.h>

void * printHola(void * arg){
    int pid = *((int *)arg);
    printf("HOLA DESDE EL HILO. Soy el hilo %d\n", pid);
    pthread_exit(NULL);
}

int saldo;

void *incrementaSaldo(void *arg){
    saldo += 100;
}


int main(){
    int NUM_THREADS = 20;
    pthread_t hiloStatus[NUM_THREADS];
    int pids[NUM_THREADS];
    saldo = 0;
    for (int i = 0; i < NUM_THREADS; i++){
        pids[i] = i;
        pthread_create(&hiloStatus[i], NULL, incrementaSaldo, NULL);
    }
    for (int i=0; i < NUM_THREADS; i++){
        pthread_join(hiloStatus[i],NULL);
    }
    printf("Saldo final %d\n", saldo);
    pthread_exit(NULL); 
}