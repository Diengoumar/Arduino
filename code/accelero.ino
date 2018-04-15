float t=0;
void setup(){ 
Serial.begin(9600);
} 
void loop() {
Serial.print("$");
Serial.print((int)(analogRead(A0)/0.2048));  
Serial.println(";"); 
t=(int)(analogRead(A0)/0.2048);
Serial.println(asin((t-1600)/330));
delay(100); 
}
