#include <iostream>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

//CLASE A USAR//

class RELOJ
{
	private:
			time_t Inicio; //time_t es un nuevo tipo de dato que viene dentro de la libreria ctime//
			int Duracion;
			time_t Fin;
	
	public:
					
			void Iniciar_Temporizador()
			{
				Inicio=time(NULL); //la funcion time() sirve para devolverme segun el argumento un valor de tiempo, en este caso el tiempo actual//
			}
			
			void Iniciar_Cronometro()
			{
				Inicio=time(NULL); //la funcion time() sirve para devolverme segun el argumento un valor de tiempo, en este caso el tiempo actual//
			}
			
			void Setter_Temporizador(int Segundos)
			{
				Duracion=Segundos;
			}
			
			int Stop_Temporizador();
			
			void Stop_Cronometro();
			
			int Tiempo_Transcurrido();
	
};
//FUNCIONES DE LA CLASE//


void RELOJ::Stop_Cronometro()
{
	Fin=time(NULL);
}

int RELOJ::Tiempo_Transcurrido()
{
	return(Fin-Inicio);
}


int RELOJ::Stop_Temporizador()
{
	time_t Tiempo_Actual;
	int Devolucion;
	
	Tiempo_Actual=time(NULL);
	if((Tiempo_Actual-Inicio)>=Duracion)
	{
		Devolucion=0;
	}
	else
	{
		Devolucion=1;
	}
	return(Devolucion);
}

//PROGRAMA PRINCIPAL//

int main(int argc, char *argv[]) 
{
	int Duracion_Temp=0,seleccionador,salir=0,Seleccionador_Cronometro,salir_cronometro=0;

	
	RELOJ Cronometro;
	RELOJ Temporizador;
	
	while(salir!=1)
	{
	
		printf("\nMENU DEL RELOJ\n\n1 - Temporizador\n2 - Cronometro\n3 - Salir del Reloj\n");
		scanf("%d",&seleccionador);
		
		switch(seleccionador)
		{
			case 1: 
					printf("\nIngrese el tiempo en segundos del temporizador: ");
					scanf("%d",&Duracion_Temp);
					
					Temporizador.Setter_Temporizador(Duracion_Temp);
					
					printf("\nTemporizador iniciado\n\nEspere por %d (segundos)\n",Duracion_Temp);
					
					Temporizador.Iniciar_Temporizador();
					
					while((Temporizador.Stop_Temporizador())!=0) //comparo en la funcion stop.temporizador el tiempo que ha pasado desde el inicio//
					{
						
					}
					
					printf("\nEl temporizador ha finalizado\n\a");
					
					system("pause");
					system("cls");
					break;
					
			case 2:
					salir_cronometro=0;
					printf("\nCuando presione una tecla el cronometro comenzara a contar\n");
					
					system("pause");
					
					Cronometro.Iniciar_Cronometro();	
					
					while(salir_cronometro!=1)
					{
					
						printf("\n\nPresione:\n1 - Detener Cronometro\n2 - Reiniciar Cronometro\n");
						scanf("%d",&Seleccionador_Cronometro);
						
						switch(Seleccionador_Cronometro)
						{
							case 1: 
									Cronometro.Stop_Cronometro();
									salir_cronometro=1;
									break;
									
							case 2: 
									Cronometro.Iniciar_Cronometro();
									system("cls");
									break;
									
							default: break;
						}
					}
					
					printf("\nEl tiempo transcurrido es: %.2d (segundos)\n",Cronometro.Tiempo_Transcurrido());
					
					printf("\nFormato(hs:min:seg) => (%.2d:%.2d:%.2d)\n",(Cronometro.Tiempo_Transcurrido()/3600),((Cronometro.Tiempo_Transcurrido()%3600)/60),(Cronometro.Tiempo_Transcurrido()%60));
					
					system("pause");
					system("cls");
					break;
					
			case 3:	
					salir=1;
					break;
					
			default: break;
		}
	}
	return 0;
}

