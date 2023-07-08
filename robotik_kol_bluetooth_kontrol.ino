
#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

const int MotorR1 = 5;  // L298N'in IN3 Girişi
const int MotorR2 = 9;  // L298N'in IN1 Girişi

const int MotorL1 = 10;  // L298N'in IN2 Girişi
const int MotorL2 = 6;   // L298N'in IN4 Girişi

#define MotorRE A2  // analog hız
#define MotorLE A3  // analog hız

int hiz = 200;



void setup() {
  myservo1.attach(8);
  myservo2.attach(11);
  myservo3.attach(3);
  myservo4.attach(4);
  pinMode(MotorR1, OUTPUT);
  pinMode(MotorR2, OUTPUT);
  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);
  pinMode(MotorRE, OUTPUT);
  pinMode(MotorLE, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) {
    String receivedString = Serial.readString();  // veri okundu
    Serial.println(receivedString);
    String servoName = receivedString.substring(0, 1);      // gelen kod okundu
    String servoValueString = receivedString.substring(2);  // boşluktan sonrası okunuyor
    int servoValue = servoValueString.toInt();              // string integere çevrildi

    if (servoName == "a") {
      myservo1.write(servoValue);
    } else if (servoName == "b") {
      myservo2.write(servoValue);
    } else if (servoName == "c") {
      myservo3.write(servoValue);
    } else if (servoName == "d") {
      myservo4.write(servoValue);
    } else if (servoName == "k") {
      hiz = servoValue;  // Noktalı virgül eklendi
    } else if (servoName == "1") {
      ileri();

    } else if (servoName == "2") {
      dur();

    } else if (servoName == "3") {
      sag();

    } else if (servoName == "4") {
      sol();

    } else if (servoName == "5") {
      geri();

    }
    //receivedString = "";
  }

}

void sag() {
  digitalWrite(MotorR1, 1);
  digitalWrite(MotorR2, 0);
  analogWrite(MotorRE, (hiz - 150));

  digitalWrite(MotorL1, 1);
  digitalWrite(MotorL2, 0);
  analogWrite(MotorLE, hiz);
  delay(100);  // "bekle" değişkeni yerine sabit bir değer kullanıldı
}

void sol() {
  digitalWrite(MotorR1, 1);
  digitalWrite(MotorR2, 0);
  analogWrite(MotorRE, hiz);

  digitalWrite(MotorL1, 1);
  digitalWrite(MotorL2, 0);
  analogWrite(MotorLE, (hiz - 150));
  delay(100);  // "bekle" değişkeni yerine sabit bir değer kullanıldı
}

void ileri() {
  digitalWrite(MotorR1, 1);
  digitalWrite(MotorR2, 0);
  analogWrite(MotorRE, hiz);

  digitalWrite(MotorL1, 1);
  digitalWrite(MotorL2, 0);
  analogWrite(MotorLE, hiz);
}

void dur() {
  analogWrite(MotorRE, 100);
  analogWrite(MotorLE, 100);
  delay(400);
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, LOW);

  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, LOW);
}

void geri() {
  digitalWrite(MotorR1, 0);
  digitalWrite(MotorR2, 1);
  analogWrite(MotorRE, hiz);

  digitalWrite(MotorL1, 0);
  digitalWrite(MotorL2, 1);
  analogWrite(MotorLE, hiz);
}
