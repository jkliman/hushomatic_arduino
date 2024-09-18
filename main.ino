int switchled1 = 1;   //pin numbers for LED on control switch
int switchled2 = 2;
int switchpin1 = A0;  //mild switch pin  
int switchpin2 = A1;  //loud switch pin
int solenoidPin = 5;
int switchState1 = 0;
int switchState2 = 0;

void setup() {

  pinMode(switchled1, OUTPUT);
  pinMode(switchled2, OUTPUT);
  pinMode(switchpin1, INPUT);
  pinMode(switchpin2, INPUT);
  pinMode(solenoidPin, OUTPUT);

  analogWrite(solenoidPin, 0); //solenoid PWM value
  digitalWrite(switchled1, LOW); //set LEDs to off
  digitalWrite(switchled2, LOW); 
}

void loop() {
  
  switchState1 = digitalRead(switchpin1); //read the state of the switch
  switchState2 = digitalRead(switchpin2); 
 
if(switchState1 == HIGH and
    switchState2 == LOW) {
      analogWrite(solenoidPin, 100); 
      digitalWrite(switchled1, HIGH); 
      digitalWrite(switchled2, LOW);
    }
if (switchState1 == LOW and
     switchState2 == HIGH) {
      digitalWrite(solenoidPin, 255);
      digitalWrite(switchled1, LOW);
      digitalWrite(switchled2, HIGH);
     }
else {
      analogWrite(solenoidPin, 0);
      digitalWrite(switchled1, LOW);
      digitalWrite(switchled2, LOW);
 }
 }
