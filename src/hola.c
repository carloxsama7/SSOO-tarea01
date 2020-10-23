#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
/* LIBRERIAS PROFESOR
#include <random>
#include <iostream>    // for cout
#include <fstream>
#include <queue>       // for queue
#include <vector>      // for vector
#include <array>
#include <future>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <csignal>


*/
int trials = 0;
void mostrar_hora(){
	time_t hora;
	time(&hora);
	printf("\nSeñal SIGUSR1 recibida: %s\n", ctime(&hora));
}
void detener( int signal_num ) { 
		
	trials++;
	//printf("Interrupt signal is (%d)\n",signal_num); 
	mostrar_hora();
	if(trials == 2){
		exit(signal_num);  
	} 
} 

int main(int argc,char* argv[]) {
	int pid=getpid();

	printf("Programa hora ejecutandose. PID: %d.\n", pid);
	while(1){
		printf("Listo para recibir la señal SIGUSR1\n");
		signal (SIGINT , mostrar_hora);
		signal(SIGTERM, detener);
		pause();
	}
	return 0; 
}