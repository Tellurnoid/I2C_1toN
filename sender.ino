//cf) https://stemship.com/arduino-beginner-i2c/

#include "Wire.h"        

void setup() {
  Wire.begin();        
}

int valFor2 = 16;
int valFor3 = 18;   //好きな値を

void loop() {      
  Wire.beginTransmission(8); //アドレス8のボードに送信       
  Wire.write(valFor2);//1バイト(＝8ビット)単位でのデータ送信しかできないため、8ビット(0～255)の範囲   
  Wire.endTransmission();        
  delay(500);
  Wire.beginTransmission(9); //アドレス9のボードに送信 
  Wire.write(valFor3);        
  Wire.endTransmission();        
  delay(500);
}