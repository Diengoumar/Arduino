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
  
 
  
  

}

void loop() {

  char recvChar; 
  //On lit caractere par caractere sur le BTSerie et on affiche sur le Terminal Serie  
  if (BTSerie.available()) {  
    recvChar = BTSerie.read(); //lecture  
   if (recvChar== '0') {
    
    digitalWrite(IN1, HIGH);   // turn the LED on (HIGH is the voltage level)
    //
   //delay(100);              // wait for a second
    // turn the LED off by making the voltage LO
    digitalWrite(IN2, LOW);
    analogWrite(ENA,0);
    
   }
   else{
     digitalWrite(IN1, HIGH);   // turn the LED on (HIGH is the voltage level)
    //
   //delay(100);              // wait for a second
    // turn the LED off by making the voltage LO
    digitalWrite(IN2, LOW);
    analogWrite(ENA,speed);
    
   }
   
    
  Serial.println(recvChar);  //ecriture
   
   }  
   
   //On lit caractere par caractere sur le terminal et on affiche sur le BT Serie 
  if (Serial.available()) {  
    recvChar = Serial.read(); //lecture
    BTSerie.write(recvChar);  //ecriture
  }  
 
}

