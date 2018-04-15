const int trig=9;
const int echo=8;
int lecture_echo=0;
void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trig,HIGH); //génération de l'impulsion Trig
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  lecture_echo=pulseIn(echo,HIGH);
  Serial.println(lecture_echo*0.017);

}
