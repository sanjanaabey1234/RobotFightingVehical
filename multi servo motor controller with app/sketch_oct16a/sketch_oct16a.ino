#include <SoftwareSerial.h> 
#include <Servo.h> 

Servo servo1; 
Servo servo2;
int TX = 10; 
int RX = 11; 

SoftwareSerial HC_06(TX, RX);  //Bluetooth TX to 10 and Bluetooth RX to 11.


void setup() {
  servo1.attach(9); 
  servo2.attach(8);
  Serial.begin(9600);
  HC_06.begin(9600);

}

void loop() {
  if(HC_06.available()> 0 ) 
  {
    int value = HC_06.read(); 
    if(value>=0 && value<=90){
      Serial.println(value); 
      int servo1_position = map(value, 0, 90, 0, 180);
      servo1.write(servo1_position);
    }
   if(value>90 && value<=180){
      Serial.println(value); 
      int servo2_position = map(value, 91, 180, 0, 180);
      servo2.write(servo2_position);
    }
  }

}

