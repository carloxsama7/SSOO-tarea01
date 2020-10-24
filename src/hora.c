#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>

int ejecuciones = 0;
/*muestra por consola el dia de la semana, hora y fecha actual del sistema*/
void mostrar_hora(){
	time_t hora;
	time(&hora);
	printf("\nSeñal SIGUSR1 recibida: %s\n", ctime(&hora));
	printf("\nListo para recibir la señal SIGUSR1\n");
}
/*permite detener la señal de un programa al ejecutarse por segunda vez*/
void detener( int numero_senal ) { 
	printf("\n");
	ejecuciones++;
	if(ejecuciones == 2){
		exit(numero_senal);  
	} 
} 
int main(int argc,char* argv[]) {
	int pid=getpid();
	printf("Programa hora ejecutandose. PID: %d.\n", pid);
	printf("Listo para recibir la señal SIGUSR1\n");
	while(1){
/*Cambia las señales originales de SIGINT y SIGTERM por las funciones definidas previamente*/		
		signal (SIGINT , detener);
		signal(SIGTERM, mostrar_hora);
		pause();
	}
	EXIT_SUCCESS; 
}