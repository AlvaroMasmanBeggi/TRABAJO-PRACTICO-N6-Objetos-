#include <iostream>
#include <string.h>
#include <ctime>
#define MAX 50
using namespace std;


//DECLARACION DE LAS CLASES A USAR//

class SENSOR
{
	private:
			char MarcaSensor[MAX];
			char TipoSensor[MAX];
			char UnidadMedida[MAX];
			
	public:
		
			//FUNCIONES PARA ESTABLECERLES VALORES A LOS SENSORES//
		
			void Setter_Marca_Sensor(char *A)
			{
				strcpy(MarcaSensor,A);
			}
			
			void Setter_Tipo_Sensor(char *A)
			{
				strcpy(TipoSensor,A);
			}
			
			void Setter_Unidad_Medida(char *A)
			{
				strcpy(UnidadMedida,A);
			}
			
			//FUNCIONES PARA OBTENER LOS VALORES DE LOS SENSORES//
			
			char *Getter_Marca_Sensor()
			{
				return(MarcaSensor);
			}
			
			char *Getter_Tipo_Sensor()
			{
				return(TipoSensor);
			}
			
			char *Getter_Unidad_Medida()
			{
				return(UnidadMedida);
			}
};

class MEDICION
{
	private:
			tm* TiempoDescompuesto;
			time_t FechaYHora;
			float ValorMedido;
			char Comentario[MAX];
	
	public:
			SENSOR SensorDeMedicion;
			int Ocultador;
			
			//SETERS//
			
			void Setter_FechaYHora()
			{
				FechaYHora=time(NULL);
			}
			
			void Setter_Valor_Medido(float Val)
			{
				ValorMedido=Val;
			}
		
			void Setter_Comentario(char *A)
			{
				strcpy(Comentario,A);
			}
			
			//GETTERS//
			
			int Getter_Dia()
			{
				TiempoDescompuesto=localtime(&FechaYHora);
				int Dia=TiempoDescompuesto->tm_mday;
				return(Dia);
			}
			
			int Getter_Mes()
			{
				TiempoDescompuesto=localtime(&FechaYHora);
				int Mes=TiempoDescompuesto->tm_mon;
				return(Mes+1);
			}
			
			int Getter_Anio()
			{
				TiempoDescompuesto=localtime(&FechaYHora);
				int Anio=TiempoDescompuesto->tm_year;
				return(Anio+1900);
			}
			
			int Getter_Hora()
			{
				TiempoDescompuesto=localtime(&FechaYHora);
				int Hora=TiempoDescompuesto->tm_hour;
				return(Hora);
			}
			
			int Getter_Minutos()
			{
				TiempoDescompuesto=localtime(&FechaYHora);
				int Minutos=TiempoDescompuesto->tm_min;
				return(Minutos);
			}
			
			int Getter_Segundos()
			{
				TiempoDescompuesto=localtime(&FechaYHora);
				int Segundos=TiempoDescompuesto->tm_sec;
				return(Segundos);
			}
			
			char *Getter_Comentario()
			{
				return(Comentario);
			}
			
			float Getter_Valor_Medido()
			{
				return(ValorMedido);
			}
			
	
};

//DECLARACION DE LAS FUNCIONES A USAR//

void Mostrar_Base_De_Datos(SENSOR Sensores[]);
void Cargar_Base_De_Datos(SENSOR Sensores[]);
void Guardar_En_Archivo(FILE *Archivo, MEDICION Mediciones[],int);
int Agregar_Medicion(SENSOR Sensores[],MEDICION Mediciones[],int cantidad);
void Mostrar_Mediciones(MEDICION Mediciones[], int cantidad);
void Eliminar_Medicion(MEDICION Mediciones[], int medicion_elim);


//PROGRAMA PRINCIPAL//

int main(int argc, char *argv[]) 
{
	//DECLARACION DE VARIABLES AUXILIARES//
	
	int SeleccionadorGeneral,contador=0,salir=0,eliminador;
	
	FILE *ArchivoDeGuardado;
	
	//DECLARACION DE LOS OBJETOS//
	
	MEDICION Mediciones[MAX];
	SENSOR Sensores[4];
	

	//BASE DE DATOS DE LOS SENSORES//
	
	Cargar_Base_De_Datos(Sensores);
	
	
	while(salir!=1)
	{
	
		printf("\nMENU PRINCIPAL\n\n1 - Agregar Medicion\n2 - Mostrar mediciones\n3 - Guardar Mediciones en un archivo\n4 - Eliminar medicion\n5 - Salir del Programa\n");
		scanf("%d",&SeleccionadorGeneral);
		switch(SeleccionadorGeneral)
		{
			case 1: 
					contador=Agregar_Medicion(Sensores,Mediciones,contador);
					
					system("cls");
					break;
			
			case 2: 
					Mostrar_Mediciones(Mediciones,contador);
					
					system("pause");
					system("cls");
					break;
					
			case 3: 
					Guardar_En_Archivo(ArchivoDeGuardado,Mediciones,contador);
					printf("\nSe guardo correctamente\n");
					system("pause");
					system("cls");
					break;
					
			case 4:
					Mostrar_Mediciones(Mediciones,contador);
					printf("\n\nIngrese el N° de Medicion a eliminar: ");
					scanf("%d",&eliminador);
					Eliminar_Medicion(Mediciones,eliminador);
					printf("\nLa Medicion N°%d se ha eliminado correctamente",eliminador);
					system("pause");
					system("cls");
					break;
					
			case 5: 
					salir=1;
					break;
			
			default: break;
			}
		
	}	
	return 0;
}


//CODIGO DE LAS FUNCIONES A USAR//

void Mostrar_Base_De_Datos(SENSOR Sensores[])
{
	int i=0;
	printf("\nLOS SENSORES REGISTRADOS SON: \n");
	for(i=1;i<4;i++)
	{
	printf("\nSENSOR %d:\n",i);
	printf("Marca: ");
	puts(Sensores[i].Getter_Marca_Sensor());
	printf("Tipo: ");
	puts(Sensores[i].Getter_Tipo_Sensor());
	printf("Unidad de Medida: ");
	puts(Sensores[i].Getter_Unidad_Medida());
	fflush(stdin);
	}
	
}

void Cargar_Base_De_Datos(SENSOR Sensores[])
{
	char Sensor0Marca[MAX]="Sony";char Sensor0Tipo[MAX]="Temperatura";char Sensor0Unidad[MAX]="Grados Centigrados";
	char Sensor1Marca[MAX]="Philps";char Sensor1Tipo[MAX]="Presion";char Sensor1Unidad[MAX]="Atmosferas";
	char Sensor2Marca[MAX]="Siemens";char Sensor2Tipo[MAX]="Lluvia";char Sensor2Unidad[MAX]="Milimetros";
	fflush(stdin);
	
	
	Sensores[1].Setter_Marca_Sensor(Sensor0Marca);
	Sensores[1].Setter_Tipo_Sensor(Sensor0Tipo);
	Sensores[1].Setter_Unidad_Medida(Sensor0Unidad);
	fflush(stdin);
	
	Sensores[2].Setter_Marca_Sensor(Sensor1Marca);
	Sensores[2].Setter_Tipo_Sensor(Sensor1Tipo);
	Sensores[2].Setter_Unidad_Medida(Sensor1Unidad);
	fflush(stdin);
	
	Sensores[3].Setter_Marca_Sensor(Sensor2Marca);
	Sensores[3].Setter_Tipo_Sensor(Sensor2Tipo);
	Sensores[3].Setter_Unidad_Medida(Sensor2Unidad);
	fflush(stdin);
}

void Guardar_En_Archivo(FILE *Archivo, MEDICION Mediciones[], int cantidad)
{
	int i;
	
	if((Archivo=fopen("RegistroDeMediciones.txt","wb+"))!=NULL)
	{
		for(i=0;i<cantidad;i++)
		{
			fwrite(&Mediciones[i],sizeof(MEDICION),1,Archivo);
		}
	}
	else
	{
		printf("\nProblemas para abrir el archivo\n");
	}
	fclose(Archivo);
}

int Agregar_Medicion(SENSOR Sensores[],MEDICION Mediciones[],int cantidad)
{
	int SeleccionadorSensor;
	float val;
	char Comentario_Aux[MAX];
	
	printf("\nSe muetra la base de sensores cargados: \n\n");
	Mostrar_Base_De_Datos(Sensores);
	
	
	printf("\nIngrese el sensor utilizado: \n");
	scanf("%d",&SeleccionadorSensor);
	switch(SeleccionadorSensor)
	{
		case 1: Mediciones[cantidad].SensorDeMedicion=Sensores[1];
		break;

		case 2: Mediciones[cantidad].SensorDeMedicion=Sensores[2];
		break;

		case 3: Mediciones[cantidad].SensorDeMedicion=Sensores[3];
		break;

		default: break;
	}
	printf("\nIngrese el valor medido: ");
	scanf("%f",&val);
	fflush(stdin);
	Mediciones[cantidad].Setter_Valor_Medido(val);

	printf("\nIngrese algun comentario: ");
	gets(Comentario_Aux);
	fflush(stdin);
	Mediciones[cantidad].Setter_Comentario(Comentario_Aux);

	Mediciones[cantidad].Setter_FechaYHora();
	
	Mediciones[cantidad].Ocultador=0;
	
	cantidad++;
	
	
	return(cantidad);
}

void Mostrar_Mediciones(MEDICION Mediciones[], int cantidad)
{
	for(int i=0;i<cantidad;i++)
	{
		if(Mediciones[i].Ocultador==0)
		{
			printf("\n\n-------------MEDICION N°%d-------------\n\n",i);
			printf("Sensor registrado: \n");
			printf("\nMarca: ");
			puts(Mediciones[i].SensorDeMedicion.Getter_Marca_Sensor());
			printf("\nTipo: ");
			puts(Mediciones[i].SensorDeMedicion.Getter_Tipo_Sensor());
			printf("\nUnidad de Medida: ");
			puts(Mediciones[i].SensorDeMedicion.Getter_Unidad_Medida());
			
			printf("\nEl valor medido es: ");
			printf("%f",Mediciones[i].Getter_Valor_Medido());
			printf("\nComentarios: ");
			puts(Mediciones[i].Getter_Comentario());
			printf("\nFecha: %d / %d / %d",Mediciones[i].Getter_Dia(),Mediciones[i].Getter_Mes(),Mediciones[i].Getter_Anio());
			printf("\nHora: %d : %d : %d",Mediciones[i].Getter_Hora(),Mediciones[i].Getter_Minutos(),Mediciones[i].Getter_Segundos());
			printf("\n\n----------------------------------\n\n");
		}
		
	}
}

void Eliminar_Medicion(MEDICION Mediciones[], int medicion_elim)
{
	char aux[5]="";
	float valor_elim=0;
	fflush(stdin);
	Mediciones[medicion_elim].Setter_Comentario(aux);
	
	Mediciones[medicion_elim].SensorDeMedicion.Setter_Marca_Sensor(aux);
	Mediciones[medicion_elim].SensorDeMedicion.Setter_Tipo_Sensor(aux);
	Mediciones[medicion_elim].SensorDeMedicion.Setter_Unidad_Medida(aux);
	
	Mediciones[medicion_elim].Setter_Comentario(aux);
	
	Mediciones[medicion_elim].Setter_Valor_Medido(valor_elim);
	
	Mediciones[medicion_elim].Ocultador=1;
	
}
