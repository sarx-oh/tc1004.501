#include <signal.h>
#include<stdio.h>
#include<unistd.h>

void no_me_matas(int signum){
    printf("Recibi la señal %d\n", signum);
    printf("No me puedes matar");
}

int condicion;
void termina_ciclo(int signum){
    condicion=2;
}

int main(){
    signal(2,no_me_matas);
    signal(10,termina_ciclo);
    condicion =1;
    while(condicion==1){
        printf("trabajando \n");
        sleep(2);
    }
    printf("Terminado");
    return 0;
}