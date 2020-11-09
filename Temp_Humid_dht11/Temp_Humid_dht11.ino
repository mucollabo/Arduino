#include "DHT.h"       // DHT.h 라이브러리를 포함한다

#define DHTPIN 2      // DHT핀을 2번으로 정의한다(DATA핀)

#define DHTTYPE DHT11  // DHT타입을 DHT11로 정의한다

#define kit 7

#define led1 5

#define led2 9

#define motion 11

int motState = LOW;

int val = 0;

DHT dht(DHTPIN, DHTTYPE);  // DHT설정 - dht (디지털2, dht11)



void setup() {

  pinMode(kit, OUTPUT);

  pinMode(led1, OUTPUT);

  pinMode(led2, OUTPUT);

  pinMode(motion, INPUT);

  Serial.begin(9600);    // 9600 속도로 시리얼 통신을 시작한다
}



void loop() {

  delay(1000);

  int h = dht.readHumidity();  // 변수 h에 습도 값을 저장

  int t = dht.readTemperature();  // 변수 t에 온도 값을 저장

  Serial.print("Humidity: ");  // 문자열 Humidity: 를 출력한다.

  Serial.print(h);  // 변수 h(습도)를 출력한다.

  Serial.print("%\t");  // %를 출력한다

  Serial.print("Temperature: ");  // 이하생략

  Serial.print(t);

  Serial.println(" C");

  if (h < 44) {
    digitalWrite(kit, HIGH);
    //delay(500);
  }
  else if (h >= 44) {
    digitalWrite(kit, LOW);
    //delay(500);
  }

  val = digitalRead(motion);         // 센서 신호값을 읽어와서 val에 저장

  if (val == HIGH) {                   // 센서 신호값이 HIGH면(인체 감지가 되면)
    digitalWrite(led2, LOW);
    for (int i = 0; i < 5; i++) {
      digitalWrite(led1, HIGH);
      delay(300);
      digitalWrite(led1, LOW);
      delay(100);
    }
    if (motState == LOW) {
      Serial.println("Welcome!");    // 시리얼 모니터 출력
      motState = HIGH;
    }
  }
  else {                             // 센서 신호값이 LOW면(인체감지가 없으면)
    digitalWrite(led1, LOW);       // 1번 LED OFF
    digitalWrite(led2, HIGH);      // 2번 LED ON
    if (motState == HIGH) {
      Serial.println("Good Bye~");   // 시리얼 모니터 출력
      motState = LOW;
    }
  }


  //digitalWrite(led2, LOW);
  //digitalWrite(led1, HIGH);
  //delay(1000);
  //digitalWrite(led1, LOW);
  //delay(100);
  //digitalWrite(led2, HIGH);
  //delay(1000);



}
