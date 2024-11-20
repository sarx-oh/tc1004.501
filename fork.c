#include <stdio.h>
#include <unistd.h>

int main(){
    int a = 5;

    int pid = fork();
    if(pid==0){
        printf("Soy el proceso hijo a = %d\n",a);
        execl("./hola", "hola", "juan", "yo", (char *) NULL); //(nombre del programa, nombre que se le asigna al sistema, ..., ...)
        printf("ESTO NO DEBERIA IMPRIMIRSE");
        return 0;
    }
    printf("Soy el proceso padre, a = %d\n", a);
    sleep(20);
    return 0;

}