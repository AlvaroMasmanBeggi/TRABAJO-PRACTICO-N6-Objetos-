#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
using namespace std;

class CADENA
{
	
	public:
	
		char cad[MAX];
	
		
		CADENA()
		{
			strcpy(cad,"Carpeta");
		}
		
		CADENA(char *A)
		{
			strcpy(cad,A);
		}
		
		void Imprimir_Cadena();
			
		int Longitud_Cadena();
		
		void Concatenar_Cadena(char *A,char *B);
		
		void Copiar_Cadena(char *A,char *B);
		
		int Buscar_Caracter_Cadena(char *A,char *B);
};

//CODIGOS DE LOS MODIFICADORES DE LA CLASE//

void CADENA::Imprimir_Cadena()
{
	puts(cad);
}

int CADENA::Longitud_Cadena()
{
	char *A=&cad[0];
	int largo=0;
	while(*A!='\0')
	{
		largo++;
		A++;
	}
	return(largo);
}

void CADENA::Concatenar_Cadena(char *A,char *B)
{
	strcat(A,B);
}

void CADENA::Copiar_Cadena(char *A,char *B)
{
	strcpy(A,B);
}

int CADENA::Buscar_Caracter_Cadena(char *A,char *B)
{
	int devolver=0;
	if((strstr(A,B))!=NULL)
	{
		devolver=1;
	}
	return(devolver);
}

//PROGRAMA PRINCIPAL//

int main(int argc, char *argv[]) 
{
	char auxcad[MAX],auxcad1[MAX],cadena_buscar[MAX];
	int seleccionador,seleccionador1,salir=0;
	
	printf("\nIngrese la cadena 1: ");
	gets(auxcad);
	fflush(stdin);
	printf("\n\nIngrese la cadena 2: ");
	gets(auxcad1);
	fflush(stdin);
	
	CADENA objeto1(auxcad);
	CADENA objeto2(auxcad1);
	CADENA objeto3();
	
	printf("\n\nSe crearon 3 objetos de la clase CADENA, dos inicializados por el usuario y otro automaticamente con valor: nulo");
	
	while(salir!=1)
	{
	
		printf("\nIngrese:\n1 - Mostrar las cadenas\n2 - Mostrar las longitudes de las cadenas\n3 - Concatenar la cadena del objeto 1 con la del objeto 2\n4 - Copiar la cadena del objeto 2 en la cadena del objeto 1\n5 - Buscar coincidencias dentro de las cadenas\n6 - Salir");
		
		scanf("%d",&seleccionador);
		
		switch(seleccionador)
		{
			case 1: 
					printf("Objeto 1: ");
					objeto1.Imprimir_Cadena();
					printf("Objeto 2: ");
					objeto2.Imprimir_Cadena();
					break;
					
			case 2: 
					printf("Tamaño de la cadena del Objeto 1: %d", objeto1.Longitud_Cadena());
					printf("\n");
					printf("Tamaño de la cadena del Objeto 2: %d", objeto2.Longitud_Cadena());
					break;
					
			case 3: 
					printf("Se concateno la cadena del objeto 1 con la cadena del objeto 2: ");
					objeto1.Concatenar_Cadena(objeto1.cad,objeto2.cad);
					printf("\nLas cadenas concatenadas: ");
					objeto1.Imprimir_Cadena();
					break;
					
			case 4: 
					printf("Se copio la cadena del objeto 2 en el objeto 1: ");
					objeto1.Copiar_Cadena(objeto1.cad,objeto2.cad);
					printf("\nLa nueva cadena del objeto 1 es: ");
					objeto1.Imprimir_Cadena();
					break;
					
			case 5:
					fflush(stdin);
					printf("\nIngrese la cadena o el caracter que desea buscar: ");
				
					gets(cadena_buscar);
					fflush(stdin);
					printf("\nDesea buscarla en:\n1 - Objeto 1\n2 - Objeto 2\n");
					scanf("%d",&seleccionador1);
					switch(seleccionador1)
					{
						case 1:
								if((objeto1.Buscar_Caracter_Cadena(objeto1.cad,cadena_buscar))==1)
								{
									printf("\nSe encontro la cadena: ( %s ) dentro del objeto 1",cadena_buscar);
								}else
								{
									printf("\nNo se encontro la cadena: ( %s ) dentro del objeto 1",cadena_buscar);
								}
								break;
								
						case 2:
								if((objeto2.Buscar_Caracter_Cadena(objeto2.cad,cadena_buscar))==1)
								{
									printf("\nSe encontro la cadena: %s dentro del objeto 2",cadena_buscar);
								}else
								{
									printf("\nNo se encontro la cadena: %s dentro del objeto 2",cadena_buscar);
								}
								break;
					}
					break;
					
			case 6: 
					salir=1;
					break;
					
			default: break;
		}
	}
	return 0;
}

