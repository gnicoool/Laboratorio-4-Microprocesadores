/*Jackelyn Nicolle Girón Villacinda
Carne 24737
Actividad 4*/

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

using std::cout;
using std::endl;

int main(){
    pid_t num_pid1 = fork();//hijo 1

    if (num_pid1 == -1) {
        perror("No se pudo crear el proceso hijo");
        exit(EXIT_FAILURE);
    }else if (num_pid1 == 0) {
        cout << "Hijo 1 - Inicio de tarea, PID: "<<getpid () << endl;
        sleep(3);//duerme tres segundos y temrina
        cout << "Hijo 1 - Fin de tarea" << endl;
        exit(1); 
    }
    
    pid_t num_pid2 = fork();//hijo 2
    
    if (num_pid2 == -1) {
        perror("No se pudo crear el segundo proceso hijo");
        exit(EXIT_FAILURE);
    }else if(num_pid2 == 0){
        cout << "Hijo 2 - Inicio de tarea, PID: " <<getpid () << endl;
        sleep(3);//duerme tres segundos y temrina
        cout << "Hijo 2 - Fin de tarea" << endl;
        exit(2);     
    }

    pid_t num_pid3 = fork();//hijo 3
    
    if (num_pid3 == -1) {
        perror("No se pudo crear el segundo proceso hijo");
        exit(EXIT_FAILURE);
    }else if(num_pid3 == 0){
        cout << "Hijo 3 - Inicio de tarea, PID : "<<getpid ()<< endl;
        sleep(3);//duerme tres segundos y temrina
        cout << "Hijo 3 - Fin de tarea" << endl;
        exit(2);     
    }

    cout << "Tareas enviadas "<< endl;//Padre termina 

    return EXIT_SUCCESS;
}