/*
Jackelyn Nicolle Girón Villacinda 
Carne 24737 
Actividad 4 
Comentar el wait de la linea 32 para ver el zombie
*/


#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

using std::cout;
using std::endl;

int main(){
    pid_t num_pid;
    
    cout << "Padre, PID: " << getpid() << endl;
    
    num_pid = fork();
    
    if (num_pid == -1) {
        perror("No se pudo crear el proceso hijo");
        exit(EXIT_FAILURE);
    } else if (num_pid == 0) {//hijo
        cout << "Hijo, PID: " << getpid() << " termina"<< endl;
        exit(EXIT_SUCCESS);
    } else {//padre
        cout << "Padre duerme" << endl;
        wait(nullptr); 
        sleep(15); // Padre duerme 15 segundos
        cout << "Termina el padre" << endl;
    }
    
    return EXIT_SUCCESS;
}