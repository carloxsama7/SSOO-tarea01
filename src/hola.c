#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
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

void mostrar_hora(){
	time_t hora;
	time(&hora);
	printf("\nSeñal SIGUSR1 recibida: %s\n", ctime(&hora));
}

int main(int argc,char* argv[]) {
	int pid=getpid();

	printf("Programa hora ejecutandose. PID: %d.\nListo para recibir la señal SIGUSR1\n", pid);
	while(1){
		signal (SIGINT , mostrar_hora);
		pause();
	}
	return 0; 
}