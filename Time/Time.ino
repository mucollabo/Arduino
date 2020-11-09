#include <Wire.h>
#include <Time.h>
#include <TimeLib.h>
#include <TimeAlarms.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C LCD 객체 선언

void setup()
{
  lcd.begin(); // lcd를 사용을 시작합니다.
  lcd.backlight(); // backlight를 On 시킵니다.
  lcd.print("Hello, world!"); // 화면에 Hello, world!를 출력합니다.
  setTime(14,29,0,1,11,11);
//  Alarm.timerRepeat(15, Repeats);            // timer for every 15 seconds   
}

void  loop(){ 
  digitalClockDisplay();
//  Alarm.delay(1000); // wait one second between clock display
}

//void Repeats() {
//    lcd.blink();
//    delay(2000);
//}


void digitalClockDisplay()
{
 
  lcd.begin(16, 3);
  lcd.print(year());
  lcd.print(".");
  lcd.print(month());
  lcd.print(".");
  lcd.print(day());

  lcd.setCursor(0, 1);
  lcd.print(hour());
  printDigits(minute());
  printDigits(second());
}

void printDigits(int digits)
{
  lcd.print(":");
  if(digits < 10)
    lcd.print('0');
  lcd.print(digits);
}
