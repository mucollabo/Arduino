//#include <core_build_options.h>
//#include <swRTC.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <TimeLib.h>
#include <TimeAlarms.h>
#define led1 13
#define ledonTime 2
#define ledoffTime 4

LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C LCD 객체 선언
//swRTC rtc;  //real time 클래스 개체 선언

void setup() {
  Serial.begin(9600);
  setTime(2, 14, 0, 10, 11, 20);
  pinMode(led1, OUTPUT);
  lcd.begin(); // lcd를 사용을 시작합니다.
  lcd.backlight(); // backlight를 On 시킵니다.
  lcd.print("Hello, Plants!__"); // 화면에 Hello, world!를 출력합니다.
  Alarm.alarmRepeat(ledonTime, 0, 0, onLed);
  Alarm.alarmRepeat(ledoffTime, 0, 0, offLed);
}

// the loop function runs over and over again forever
void loop() {
  Alarm.delay(1000);
  if (hour() >= ledonTime and hour() < ledoffTime) {
    onLed();
  }
  else {
    offLed();
  }
}


void onLed() {
  digitalWrite(led1, HIGH);
  lcd.print("LED On!_________");
}

void offLed() {
  digitalWrite(led1, LOW);
  lcd.print("LED Off!________");
}
