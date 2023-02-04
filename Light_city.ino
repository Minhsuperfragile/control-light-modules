int den1 = 2;
int den2 = 3;
int den3 = 4;
int den4 = 5;
int den5 = 6;

void setup() {
  pinMode(den1, OUTPUT);
  pinMode(den2, OUTPUT);
  pinMode(den3, OUTPUT);
  pinMode(den4, OUTPUT);
  pinMode(den5, OUTPUT);

  digitalWrite(den1, LOW);
  digitalWrite(den2, LOW);
  digitalWrite(den3, LOW);
  digitalWrite(den4, LOW);
  digitalWrite(den5, LOW);

  Serial.begin(9600);
}

void lightSwitch(int lightNumber){
  int state;
  state = digitalRead(lightNumber);
  if(state == 0){
    digitalWrite(lightNumber,HIGH);
    Serial.print("Bat den so ");
  }
  else{
    digitalWrite(lightNumber,LOW);
    Serial.print("Tat den so ");
  }
  Serial.println((lightNumber-1));
};

void loop() {

  byte incomingByte;
  incomingByte = Serial.read();    

  switch(incomingByte) {
    case 49:
      lightSwitch(den1);
      break;

    case 50:
      lightSwitch(den2);
      break;

    case 51:
      lightSwitch(den3);
      break;

    case 52:
      lightSwitch(den4);
      break;
      
    case 53:
      lightSwitch(den5);
      break;
    case 54:
      digitalWrite(den2,LOW);
      break;
  }

}
