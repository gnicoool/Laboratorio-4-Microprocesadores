/*Jackelyn Nicolle Girón Villacinda
Carne 24737
Actividad 3*/

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

using std::cout;
using std::endl;

int main(){
    pid_t num_pid;				
    num_pid = fork();//proceso hijo

    if (num_pid == -1) {
        perror("No se pudo crear el proceso hijo");
        exit(EXIT_FAILURE);
    }else if (num_pid == 0) {
        cout<< "Hijo, el PID es: " << getpid() << " el PID del padre es: "<< getppid() <<endl;

        pid_t num_pid2;
        num_pid2 = fork(); //proceso nieto

        if(num_pid2 == -1){
            perror("No se pudo crear el proceso nieto");
            exit(EXIT_FAILURE);
        }else if(num_pid2 == 0){
            cout<< "Nieto, el PID es: " << getpid() << " el PID del padre es: "<< getppid() <<endl;

            pid_t num_pid3;
            num_pid3 = fork(); //proceso bisnieto

            if(num_pid3 == -1){
                perror("No se pudo crear el proceso bisnieto");
                exit(EXIT_FAILURE);
            }else if(num_pid3 == 0){
                cout<< "Bisnieto, el PID es: " << getpid() << " el PID del padre es: "<< getppid() <<endl;
                cout<< "\nEl bisnieto termino" << endl;
                exit(EXIT_SUCCESS); // Termina bisnieto
            } else {
                wait(nullptr); // Espera al bisnieto
                cout<< "El nieto termino" << endl;
                exit(EXIT_SUCCESS); // Termina el nieto
            }
        }else {
            wait(nullptr); // Espera al nieto
            cout<< "El hijo termino" << endl;
            exit(EXIT_SUCCESS); // Termina el hijo
        }
    }else {
        wait(nullptr); // Espera al hijo
        cout<< "\nEl PID del padre es: " << getpid() << endl;
    }

    return EXIT_SUCCESS;
}