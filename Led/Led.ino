//#include <core_build_options.h>
//#include <swRTC.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <TimeLib.h>
#include <TimeAlarms.h>
#define led1 13

LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C LCD 객체 선언
swRTC rtc;  //real time 클래스 개체 선언

void setup() {
  Serial.begin(9600);
  setTime(0, 40, 0, 10, 11, 20);
  pinMode(led1, OUTPUT);
  
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(1000);                       // wait for a second
//  digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
//  delay(1000);                       // wait for a second
}
