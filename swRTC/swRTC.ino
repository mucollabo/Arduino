#include <core_build_options.h>
#include <swRTC.h>

swRTC rtc;  //클래스 개체 선언

void setup() {
  rtc.stopRTC();            //정지
  rtc.setTime(14, 43, 10);  //시, 분, 초
  rtc.setDate(9, 11, 2020); //일, 월, 년
  rtc.startRTC();           //시작
  Serial.begin(9600);
}

void loop() {
  Serial.print(rtc.getHours(), DEC);
  Serial.print(":");
  Serial.print(rtc.getMinutes(), DEC);
  Serial.print(":");
  Serial.print(rtc.getSeconds(), DEC);
  Serial.print("\t"); 

  Serial.print(rtc.getYear(), DEC);
  Serial.print("/");
  Serial.print(rtc.getMonth(), DEC);
  Serial.print("/");
  Serial.println(rtc.getDay(), DEC);
  delay(1000);
}
