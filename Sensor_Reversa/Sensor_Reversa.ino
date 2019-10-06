const int Zumbador = PA4; // Zumbador
const int Trigger = PA6;   //Pin digital PA6 para el Trigger del sensor
const int Echo = PA5;   //Pin digital PA5 para el Echo del sensor
long t; //timepo que demora en llegar el eco
long d; 
const int Led = PA7;  





void setup() {

  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  pinMode(Zumbador, OUTPUT);
  pinMode (Led, OUTPUT);
  
 
}

void loop() {

  digitalWrite(Led,LOW);
  distancia();


  
  if(d>=100 && d<200){

    sonar1();
    
    
  }else if(d>=50 && d <100){


    sonar2();
    
  }else if(d>=20 && d<50){

    sonar3();
    

    
  }else if(d>=10 && d <20){

    sonar4();
    
    
  }else if(d<10){


    sonar5();
    
  }
  
  
  
  

}

void distancia(){

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); 
  d = t/59;             
  
  Serial.print("Distancia: ");
  Serial.println(d);
  Serial.println();
  delay(100);          


}

void sonar1()
{
  
  digitalWrite(Zumbador, HIGH);
  delay(100);
  digitalWrite(Zumbador, LOW);
  delay(2000);
  
}

void sonar2()
{
  
  digitalWrite(Zumbador, HIGH);
  delay(100);
  digitalWrite(Zumbador, LOW);
  delay(1000);
  
}

void sonar3()
{
  
  digitalWrite(Zumbador, HIGH);
  delay(100);
  digitalWrite(Zumbador, LOW);
  delay(500);
  
}

void sonar4()
{
  
  digitalWrite(Zumbador, HIGH);
  delay(100);
  digitalWrite(Zumbador, LOW);
  delay(250);
  
}

void sonar5()
{
  
  digitalWrite(Zumbador, HIGH);
  delay(100);
  digitalWrite(Zumbador, LOW);
  delay(100);
  
}
