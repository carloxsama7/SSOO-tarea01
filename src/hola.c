#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>

int ejecuciones = 0;

void mostrar_hora(){
	time_t hora;
	time(&hora);
	printf("\nSeñal SIGUSR1 recibida: %s\n", ctime(&hora));
}
void detener( int numero_senal ) { 
	ejecuciones++;
	mostrar_hora();
	if(ejecuciones == 2){
		exit(numero_senal);  
	} 
} 

int main(int argc,char* argv[]) {
	int pid=getpid();
	printf("Programa hora ejecutandose. PID: %d.\n", pid);
	while(1){
		printf("Listo para recibir la señal SIGUSR1\n");
		signal (SIGINT , detener);
		signal(SIGTERM, mostrar_hora);
		pause();
	}
	return 0; 
}