//CABE�ALHO
/*	Arquivo: VUmeterArduino.cpp
	Vers�o: (1.0.0)
	Autor: Luiz Fantin Neto
 */

//Constantes associadas aos pinos do arduino
int const pinclock = 12; //ligado ao clock dos dois CI's 74HC595
int const latch = 8; //ligado ao latch do CI 74HC595 determinado como menos significativo
int const latch2 = 5; //ligado ao latch do CI 74HC595 determinado como mais significativo
int const data  = 11; //ligado ao data dos dois CI's 74HC595
int micro = A0,numero,menor=512,maior=512,ampli;

unsigned long previousMillis = 0;// Variavel responsavel pelo controle de tempo atrav�s da fun��o "millis()"
const long intervalo = 50; // Intervalo de tempo de atualiza��o dos estados dos LED's


void setup() {
  //definindo os pinos como de sa�da
  pinMode(pinclock,OUTPUT);
  pinMode(latch,OUTPUT);
  pinMode(latch2,OUTPUT);
  pinMode(data,OUTPUT);
  Serial.begin(9600);
}
 
void loop() 
{    //Leitura do valor da sa�da anal�gica do m�dulo MICROFONE
     numero = analogRead(micro);


     //Utilizando o n�mero medido para determinar a amplitude do sinal em cada momento de leitura
     if(numero<512)
     menor=numero;

     if(numero>512)
     maior=numero;

     ampli=((maior-512)+(512-menor))/2;

     //Verificando o descorrimento de tempo do programa
     unsigned long currentMillis = millis();

     
    // Se o tempo descorrido for maior que o intervalo pr� estabelecido, mudamos os estados dos LED's
    if (currentMillis - previousMillis >= intervalo) 
    {
      previousMillis = currentMillis;
      Serial.println(ampli);

      //Determina��o das escalas de amplitude do programa. Como estamos trabalhando com 16 bits, utilizaremos 16 escalas (condi��es) diferentes.
      if((ampli>1)&&(ampli<10))
      {
        digitalWrite(latch, LOW); //Habilitando o CI menos significativo para receber dados.
        shiftOut(data, pinclock, MSBFIRST, 1);//Fun��o respons�vel por enviar dados de forma sincrona pro CI menos significativo.
        digitalWrite(latch, HIGH);//Desabilitando o CI menos significativo para n�o receber mais dados.

        digitalWrite(latch2, LOW);//Habilitando o CI mais significativo para receber dados.
        shiftOut(data, pinclock, MSBFIRST, 0);//Fun��o respons�vel por enviar dados de forma sincrona pro CI mais significativo.
        digitalWrite(latch2, HIGH);//Desabilitando o CI mais significativo para n�o receber mais dados.
      }
      else if((ampli>10)&&(ampli<30))
      {
        digitalWrite(latch, LOW);
        shiftOut(data, pinclock, MSBFIRST, 3);
        digitalWrite(latch, HIGH);

        digitalWrite(latch2, LOW);
        shiftOut(data, pinclock, MSBFIRST, 0);
        digitalWrite(latch2, HIGH);
      }
      else if((ampli>50)&&(ampli<70))
      {
        digitalWrite(latch, LOW);
        shiftOut(data, pinclock, MSBFIRST, 7);
        digitalWrite(latch, HIGH);

        digitalWrite(latch2, LOW);
        shiftOut(data, pinclock, MSBFIRST, 0);
        digitalWrite(latch2, HIGH);
      }
      else if((ampli>70)&&(ampli<90))
      {
        digitalWrite(latch, LOW);
        shiftOut(data, pinclock, MSBFIRST, 15);
        digitalWrite(latch, HIGH);

        digitalWrite(latch2, LOW);
        shiftOut(data, pinclock, MSBFIRST, 0);
        digitalWrite(latch2, HIGH);
      }
      else if((ampli>90)&&(ampli<120))
      {
        digitalWrite(latch, LOW);
        shiftOut(data, pinclock, MSBFIRST, 31);
        digitalWrite(latch, HIGH);

        digitalWrite(latch2, LOW);
        shiftOut(data, pinclock, MSBFIRST, 0);
        digitalWrite(latch2, HIGH);
      }
      else if((ampli>120)&&(ampli<130))
      {
        digitalWrite(latch, LOW);
        shiftOut(data, pinclock, MSBFIRST, 63);
        digitalWrite(latch, HIGH);

        digitalWrite(latch2, LOW);
        shiftOut(data, pinclock, MSBFIRST, 0);
        digitalWrite(latch2, HIGH);
      }
      else if((ampli>130)&&(ampli<150))
      {
        digitalWrite(latch, LOW);
        shiftOut(data, pinclock, MSBFIRST, 127);
        digitalWrite(latch, HIGH);

        digitalWrite(latch2, LOW);
        shiftOut(data, pinclock, MSBFIRST, 0);
        digitalWrite(latch2, HIGH);
      }
      else if((ampli>150)&&(ampli<160))
      {
        digitalWrite(latch, LOW);
        shiftOut(data, pinclock, MSBFIRST, 255);
        digitalWrite(latch, HIGH);

        digitalWrite(latch2, LOW);
        shiftOut(data, pinclock, MSBFIRST, 0);
        digitalWrite(latch2, HIGH);
      }
      else if((ampli>160)&&(ampli<170))
      {
        digitalWrite(latch, LOW);
        shiftOut(data, pinclock, MSBFIRST, 255);
        digitalWrite(latch, HIGH);

        digitalWrite(latch2, LOW);
        shiftOut(data, pinclock, MSBFIRST, 1);
        digitalWrite(latch2, HIGH);
      }
      else if((ampli>170)&&(ampli<180))
      {
        digitalWrite(latch, LOW);
        shiftOut(data, pinclock, MSBFIRST, 255);
        digitalWrite(latch, HIGH);

        digitalWrite(latch2, LOW);
        shiftOut(data, pinclock, MSBFIRST, 3);
        digitalWrite(latch2, HIGH);
      }
      else if((ampli>180)&&(ampli<190))
      {
        digitalWrite(latch, LOW);
        shiftOut(data, pinclock, MSBFIRST, 255);
        digitalWrite(latch, HIGH);

        digitalWrite(latch2, LOW);
        shiftOut(data, pinclock, MSBFIRST, 7);
        digitalWrite(latch2, HIGH);
      }
      else if((ampli>190)&&(ampli<200))
      {
        digitalWrite(latch, LOW);
        shiftOut(data, pinclock, MSBFIRST, 255);
        digitalWrite(latch, HIGH);

        digitalWrite(latch2, LOW);
        shiftOut(data, pinclock, MSBFIRST, 15);
        digitalWrite(latch2, HIGH);
      }
      else if((ampli>200)&&(ampli<210))
      {
        digitalWrite(latch, LOW);
        shiftOut(data, pinclock, MSBFIRST, 255);
        digitalWrite(latch, HIGH);

        digitalWrite(latch2, LOW);
        shiftOut(data, pinclock, MSBFIRST, 31);
        digitalWrite(latch2, HIGH);
      }
      else if((ampli>210)&&(ampli<220))
      {
        digitalWrite(latch, LOW);
        shiftOut(data, pinclock, MSBFIRST, 255);
        digitalWrite(latch, HIGH);

        digitalWrite(latch2, LOW);
        shiftOut(data, pinclock, MSBFIRST, 63);
        digitalWrite(latch2, HIGH);
      }
      else if((ampli>220)&&(ampli<230))
      {
        digitalWrite(latch, LOW);
        shiftOut(data, pinclock, MSBFIRST, 255);
        digitalWrite(latch, HIGH);

        digitalWrite(latch2, LOW);
        shiftOut(data, pinclock, MSBFIRST, 127);
        digitalWrite(latch2, HIGH);
      }
      else if(ampli>230)
      {
        digitalWrite(latch, LOW);
        shiftOut(data, pinclock, MSBFIRST, 255);
        digitalWrite(latch, HIGH);

        digitalWrite(latch2, LOW);
        shiftOut(data, pinclock, MSBFIRST, 255);
        digitalWrite(latch2, HIGH);
      }
    }     
}
