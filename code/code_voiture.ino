//**********************************************
//Code de reference pour le module bluetooth HC-06  
// envoi de commandes AT et affichage de la rÃ©ponse du module
//
//***********************************************/*  
#include <SoftwareSerial.h>  //Software Serial Port  
#define RxD 10    //Pin 10 pour RX, PB2 sur votre board, a brancher sur le TX du HC-06
#define TxD 11    //Pin 11 pour TX, PB3 sur votre board, a brancher sur le RX du HC-06
SoftwareSerial BTSerie(RxD,TxD);  

const int ENA=5; 
const int IN1=7;
const int IN2=8; 
const int ENB=12; 
const int IN3=13;
const int IN4=14;
int speed=210;
void setup() {
    Serial.begin(9600);
    // Configuration du bluetooth  
  pinMode(RxD, INPUT);  
  pinMode(TxD, OUTPUT);  
  BTSerie.begin(9600); 
  Serial.println("En attente de la commandes AT"); 
   delay(100);
  // Test des commandes AT  
  BTSerie.print("AT+VERSION");  //Demande le NÂ° de version 
  delay(1000);  
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(ENA,OUTPUT);
   pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENB,OUTPUT);
  
 
  
  

}

void loop() {

  char recvChar; 
  //On lit caractere par caractere sur le BTSerie et on affiche sur le Terminal Serie  
  if (BTSerie.available()>0) {  
    recvChar = BTSerie.read(); //lecture  
   
    if(recvChar=='1'){
    digitalWrite(IN1, HIGH);  
   
    digitalWrite(IN2, LOW);
    analogWrite(ENA,speed);
    
   }
   else if(recvChar=='M'){
     digitalWrite(IN1, LOW);  

    digitalWrite(IN2, HIGH);
    analogWrite(ENA,speed);
    
   }
   else if(recvChar=='D'){
     digitalWrite(IN3, LOW);   
  LO
    digitalWrite(IN4, HIGH);
    analogWrite(ENB,-50);
    
   }
   else if(recvChar=='G'){
     digitalWrite(IN3, HIGH);  
  
    digitalWrite(IN4, LOW);
    analogWrite(ENB,speed);
   }
   else{
     digitalWrite(IN1, HIGH);   

    digitalWrite(IN2, LOW);
    analogWrite(ENA,0);
    analogWrite(ENB,0);
    
 
    
   }
  
   
  Serial.println(recvChar);  //ecriture
    
   
   }  
   
   //On lit caractere par caractere sur le terminal et on affiche sur le BT Serie 
  if (Serial.available()) {  
    recvChar = Serial.read(); //lecture
    BTSerie.write(recvChar);  //ecriture
  }  
 
}

