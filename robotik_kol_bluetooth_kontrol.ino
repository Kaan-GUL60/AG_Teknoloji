#include <SoftwareSerial.h>
#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

#define MotorR1 4
#define MotorR2 8
#define MotorRE A2  // analog hız

#define MotorL1 12
#define MotorL2 13
#define MotorLE A3  // analog hız

int hiz = 255;

int bluetoothTx = 10; // bluetooth tx 10 pin
int bluetoothRx = 11; // bluetooth rx 11 pin

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup() {
  myservo1.attach(9);
  myservo2.attach(8);
  myservo3.attach(7);
  myservo4.attach(6);
  pinMode(MotorR1, OUTPUT);
  pinMode(MotorR2, OUTPUT);
  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);

  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {

  if (bluetooth.available() > 0) {
    String receivedString = bluetooth.readString(); // veri okundu
    Serial.println(receivedString);

    String servoName = receivedString.substring(0, 1); // gelen kod okundu
    String servoValueString = receivedString.substring(2); // boşluktan sonrası okunuyor
    int servoValue = servoValueString.toInt(); // string integere çevrildi

    if (servoName == "a") {
      myservo1.write(servoValue);
    }
    else if (servoName == "b") {
      myservo2.write(servoValue);
    }
    else if (servoName == "c") {
      myservo3.write(servoValue);
    }
    else if (servoName == "d") {
      myservo4.write(servoValue);
    }
    else if (servoName == "k") {
      hiz = servoValue; // Noktalı virgül eklendi
    }
    else if (servoName == "1") {
      ileri();
    }
    else if (servoName == "2") {
      dur();
    }
    else if (servoName == "3") {
      sag();
    }
    else if (servoName == "4") {
      sol();
    }
    else if (servoName == "5") {
      geri();
    }
  }
}

void sag() {
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, HIGH);
  analogWrite(MotorRE, (hiz - 300));

  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, HIGH);
  analogWrite(MotorLE, hiz);
  delay(100); // "bekle" değişkeni yerine sabit bir değer kullanıldı
}

void sol() {
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, HIGH);
  analogWrite(MotorRE, hiz);

  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, HIGH);
  analogWrite(MotorLE, (hiz - 300));
  delay(100); // "bekle" değişkeni yerine sabit bir değer kullanıldı
}

void ileri() {
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, HIGH);
  analogWrite(MotorRE, hiz);

  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, HIGH);
  analogWrite(MotorLE, hiz);
}

void dur() {
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, LOW);

  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, LOW);
}

void geri() {
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, LOW);
  analogWrite(MotorRE, hiz);

  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, HIGH);
  analogWrite(MotorLE, hiz);
}
