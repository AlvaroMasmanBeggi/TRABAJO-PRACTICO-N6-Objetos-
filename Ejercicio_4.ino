class RELOJ
{
  private:
          unsigned long Inicio;
          unsigned long Duracion;
          unsigned long Fin;

  public:
          //FUNCIONES PARA EL TEMPORIZADOR//

          void Iniciar_Temporizador()
          {
            Inicio=millis();
          }

          void Setter_Temporizador(unsigned long Largo)
          {
            Duracion=Largo;
          }
          
          int Stop_Temporizador()
          {
            unsigned long TiempoActual;
            int Devolucion;

            TiempoActual=millis();
            if((TiempoActual-Inicio)>=Duracion)
            {
              Devolucion=0;
            }
            else
            {
              Devolucion=1;
            }
            return(Devolucion);
          }

          //FUNCIONES PARA EL CRONOMETRO//

           void Iniciar_Cronometro()
          {
            Inicio=millis();
          }

          void Stop_Cronometro()
          {
            Fin=millis();
          }

          unsigned long Tiempo_Transcurrido()
          {
            return(Fin-Inicio);
          }

};

//SETEO LOS PINES DEL ARDUINO//

int LedStop = 13;
int LedStart = 12;


//VARIABLES AUXILIARES//

unsigned long DuracionTemporizador;
unsigned long TiempoCronometrizado;
RELOJ Cronometro;

//PROGRAMA PRINCIPAL DE ARDUINO//

void setup() 
{
  // put your setup code here, to run once:

  pinMode(LedStop, OUTPUT); //ESTE PIN 13 SE PRENDE CUANDO SE DETIENE EL CRONOMETRO O TEMPORIZADOR//
  pinMode(LedStart, OUTPUT);  //ESTE PIN 12 SE PRENDE CUANDO SE INICIA EL CRONOMETRO O TEMPORIZADOR//
  Serial.begin(9600);
  Serial.println("TEMPORIZADOR\n");

}

void loop() 
{
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0) 
  {
    char comando = Serial.read();

    if (comando == 'A') 
    {
      Cronometro.Iniciar_Cronometro();
      digitalWrite(LedStart, HIGH); // Enciende el LED
      digitalWrite(LedStop, LOW);
    }
     else if (comando == 'D') 
    {
      Cronometro.Stop_Cronometro();
      digitalWrite(LedStop, HIGH); // 
      digitalWrite(LedStart, LOW);
      TiempoCronometrizado=Cronometro.Tiempo_Transcurrido();
      Serial.print(TiempoCronometrizado*0.001,DEC);
      Serial.println(" Segundos");
    }
    else if(comando == 'R')
    {
      Cronometro.Iniciar_Cronometro();
      digitalWrite(LedStop, HIGH); // Enciende el LED
      digitalWrite(LedStop, LOW);
      delay(250);
      digitalWrite(LedStop, HIGH); // Enciende el LED
      digitalWrite(LedStop, LOW);
    }
  }

}
