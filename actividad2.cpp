/*Jackelyn Nicolle Girón Villacinda
Carne 24737
Actividad 2*/

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

using std::cout;
using std::endl;
int main(){
    pid_t num_pid1;
    num_pid1 = fork();//hijo 1

    if (num_pid1 == -1) {
        perror("No se pudo crear el proceso hijo");
        exit(EXIT_FAILURE);
    }else if (num_pid1 == 0) {
        sleep(2);//duerme dos segundos y temrina
        exit(1); 
    }else { 
        pid_t num_pid2 = fork();//hijo 2
        if (num_pid2 == -1) {
            perror("No se pudo crear el segundo proceso hijo");
            exit(EXIT_FAILURE);
        }else if(num_pid2 == 0){
            sleep(5); // duerme cinco segundos y termina
            exit(2); 
        }
        
    }

    int status;
    pid_t terminado;
    bool hijo1Termino = false;
    bool hijo2Termino = false;

    for (int i = 0; i < 2; ++i) {//padre
        terminado = wait(&status);
        if(WIFEXITED(status)) {
           int codigo = WEXITSTATUS(status);
            if( codigo == 1 ) {
                if (!hijo2Termino) {
                    cout << "El hijo 1 termino primero" << endl;
                }else{cout << "El hijo 1 termino " << endl;}
                hijo1Termino = true;
            
            } else if( codigo == 2 ) {
                if (!hijo1Termino) {
                    cout << "El hijo 2 termino primero" << endl;
                }else{cout << "El hijo 2 termino" << endl;}
                hijo2Termino = true;
            }
        }
    }

    return EXIT_SUCCESS;
    
}