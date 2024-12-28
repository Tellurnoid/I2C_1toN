//cf) https://stemship.com/arduino-beginner-i2c/

#include "Wire.h"

#define LED 13
volatile byte receiveValue;       

void setup() {
  Wire.begin(8); //自分のアドレスを自由に設定。宛先に使われる。8以上の値
  Wire.onReceive(dataReceive);      
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  Serial.println(receiveValue);
  if(receiveValue==16){digitalWrite(LED, HIGH);}else{digitalWrite(LED, LOW);}
}

void dataReceive(int Number) {        
  if(Wire.available())        
    receiveValue = Wire.read();       
}