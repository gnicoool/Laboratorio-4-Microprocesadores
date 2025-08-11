/* Jackelyn Nicolle Girón Villacinda
Carné 24737
Actividad 1
*/
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

using std::cout;
using std::endl;

int main(){
    pid_t num_pid;				
	num_pid = fork();

    if (num_pid == -1) {
        perror("No se pudo crear el proceso hijo");
        exit(EXIT_FAILURE);
    }else if(num_pid > 0){
        for(int i = 0; i < 3; ++i) {//padre
            cout  << "soy el padre " << endl;
            sleep(2); // espera dos segundos para imprimir mensaje
        }
        wait(nullptr); // espera a que el hijo termine
    }else {//hijo
        for(int i = 0; i < 6; ++i) {
            cout  << "soy el hijo " << endl;
            sleep(1); // espera un segundo para imprimir mensaje
        }
        exit(EXIT_SUCCESS);
    }

    return EXIT_SUCCESS;
}