const int Trigger = PA6;   //Pin digital PA6 para el Trigger del sensor
const int Echo = PA5;   //Pin digital PA% para el Echo del sensor
long t; //timepo que demora en llegar el eco
long d; //distancia en centimetros
const int zum=PA4; //Zumbador
const int Led = PC13; //Led pc13



//Distancia bicicletas


void setup() {

  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  pinMode(zum, OUTPUT);
  pinMode (Led, OUTPUT);

  
  

}

void loop() {
  // put your main code here, to run repeatedly:

  distancia();
  
char leer = Serial.read();


      Serial.print("Distancia: ");
      Serial.print(d);      //Enviamos serialmente el valor de la distancia
      Serial.print("cm");
      Serial.println();
      delay(400);
  

  
  
  if(d<150){
   
      Serial.print("¡Precaucion, estás demasiado cerca del vehiculo!");
      Serial.println();
      Serial.print("Distancia: ");
      Serial.print(d);      //Enviamos serialmente el valor de la distancia
      Serial.print("cm");
      Serial.println();
      
      encenderLed();
      sonar();
      delay(500);
      sonar();
      
      
     
    
  }


}

void distancia(){

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  //////
  
  delay(100);          //Hacemos una pausa de 100ms
///////////
}

void sonar()
{
  
  digitalWrite(zum, HIGH);
  delay(50);
  digitalWrite(zum, LOW);
  delay(20);
  
}

void encenderLed()
{

  digitalWrite(Led,HIGH);
  delay(100);
  digitalWrite(Led,LOW);
  delay(100);
  
  
}
