/* 
Jackelyn Nicolle Girón Villacinda
Carné 24737
Actividad 6 */

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

using std::cout;
using std::endl;
using std::cin;
int main() {
    int pipe_PadreHijo[2]; // Pipe para enviar número del padre al hijo
    int pipe_HijoPadre[2]; // Pipe para enviar resultado del hijo al padre

    if (pipe(pipe_PadreHijo) == -1 || pipe(pipe_HijoPadre) == -1) {
        perror("Error al crear los pipes");
        exit(EXIT_FAILURE);
    }

    pid_t num_pid;
    num_pid = fork();

    if (num_pid == -1) {
        perror("Error al crear el proceso hijo");
        exit(EXIT_FAILURE);
    } else if (num_pid == 0) {//hijo
        close(pipe_PadreHijo[1]); 
        close(pipe_HijoPadre[0]);

        int numero;
        read(pipe_PadreHijo[0], &numero, sizeof(numero)); // Lee numero del padre
        cout << "Hijo recibió el numero : " << numero << " y enviara al padre el cuadrado de ese numero"<< endl;

        int resultado = numero * numero;
        write(pipe_HijoPadre[1], &resultado, sizeof(resultado)); // Enviar resultado al padre

        close(pipe_PadreHijo[0]);
        close(pipe_HijoPadre[1]);

        exit(EXIT_SUCCESS);
    } else {//padre
        // Cerrar extremos no usados
        close(pipe_PadreHijo[0]);
        close(pipe_HijoPadre[1]); 

        int numero;
        cout << "Ingrese un numero entero para que el padre lo envie al hijo: ";
        cin >> numero; // Leer numero del usuario
        write(pipe_PadreHijo[1], &numero, sizeof(numero)); // envia numero al hijo

        int resultado;
        read(pipe_HijoPadre[0], &resultado, sizeof(resultado)); // lee resultado del hijo
        cout << "Padre recibió el resultado: " << resultado << endl;

        close(pipe_PadreHijo[1]);
        close(pipe_HijoPadre[0]);

        wait(nullptr);
    }

    return EXIT_SUCCESS;
}
