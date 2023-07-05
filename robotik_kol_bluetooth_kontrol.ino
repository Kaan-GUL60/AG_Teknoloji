
#define MotorR1 26
#define MotorR2 27
#define MotorRE 25  //analog hiz

#define MotorL1 21
#define MotorL2 16
#define MotorLE 17  //analog hiz

int hiz = 180; 


// Step motor pinleri
const int motor1StepPin = 2;
const int motor1DirPin = 3;
const int motor2StepPin = 4;
const int motor2DirPin = 5;
const int motor3StepPin = 6;
const int motor3DirPin = 7;

// Step motor pinleri


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(MotorR1, OUTPUT);
  pinMode(MotorR2, OUTPUT);
  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    char mesaj = Serial.read();
    Serial.println(mesaj);

    if(mesaj == '1'){   //ARABA DÜZ GİDECEK kodlarınız yaz buradaki if'in içine
      //bluetooth dan 1 değeri gönderilirse bunları yap yapılacak işlem
      ileri();

      }
    if(mesaj == '2'){   //ARABA DURACAK kodlarınız yaz buradaki if'in içine
        //bluetooth dan 2 değeri gönderilirse bunları yap yapılacak işlem
        dur();

      }
    if(mesaj == '3'){    //ARABA SAĞA DÖNECEK kodlarınız yaz buradaki if'in içine
        //bluetooth dan 3 değeri gönderilirse bunları yap yapılacak işlem
        yerindesag();
      }
    if(mesaj == '4'){    //ARABA SOLA DÖNECEK kodlarınız yaz buradaki if'in için
        //bluetooth dan 4 değeri gönderilirse bunları yap yapılacak işlem
        yerindesol();

      }
    if(mesaj == '5'){     //KOLU KENDİ ETRAFINDA DÖNDER kodlarınız yaz buradaki if'in içine
     
       //bluetooth dan 5 değeri gönderilirse bunları yap yapılacak işlem
      // Motor 2'yi sağa döndür
      digitalWrite(motor2DirPin, LOW);
      for (int i = 0; i < 100; i++) {
        digitalWrite(motor2StepPin, HIGH);
        delayMicroseconds(500);
        digitalWrite(motor2StepPin, LOW);
        delayMicroseconds(500);
      }
    }
      if(mesaj == 'a'){
        // Motor 3'ü sağa döndür
      digitalWrite(motor3DirPin, LOW);
      for (int i = 0; i < 100; i++) {
        digitalWrite(motor3StepPin, HIGH);
        delayMicroseconds(500);
        digitalWrite(motor3StepPin, LOW);
        delayMicroseconds(500);
      }


      }
    if(mesaj == '6'){     //KOLU AŞAĞI İNDİR kodlarınız yaz buradaki if'in içine
        //bluetooth dan 6 değeri gönderilirse bunları yap yapılacak işlem
        digitalWrite(motor1DirPin, HIGH);
        for (int i = 0; i < 100; i++) {
          digitalWrite(motor1StepPin, HIGH);
          delayMicroseconds(500);
          digitalWrite(motor1StepPin, LOW);
          delayMicroseconds(500);
        }


      }
    if(mesaj == '7'){     //KOLU YUKARI KALDIR kodlarınız yaz buradaki if'in içine
        //bluetooth dan 7 değeri gönderilirse bunları yap yapılacak işlem
        // Motor 1'i sağa döndür
        digitalWrite(motor1DirPin, LOW);
        for (int i = 0; i < 100; i++) {
          digitalWrite(motor1StepPin, HIGH);
          delayMicroseconds(500);
          digitalWrite(motor1StepPin, LOW);
          delayMicroseconds(500);
        }

      }
    if(mesaj == '8'){     //EL İLE TOPU TUTMA kodlarınız yaz buradaki if'in içine
      //bluetooth dan 8 değeri gönderilirse bunları yap yapılacak işlem
      // Motor 2'yi sola döndür
      digitalWrite(motor2DirPin, HIGH);
      for (int i = 0; i < 100; i++) {
        digitalWrite(motor2StepPin, HIGH);
        delayMicroseconds(500);
        digitalWrite(motor2StepPin, LOW);
        delayMicroseconds(500);
      }


      }
    if(mesaj == '9'){     // EL İLE TOPU BIRAKMA kodlarınız yaz buradaki if'in içine
        // Motor 2'yi sağa döndür
        digitalWrite(motor2DirPin, LOW);
        for (int i = 0; i < 100; i++) {
          digitalWrite(motor2StepPin, HIGH);
          delayMicroseconds(500);
          digitalWrite(motor2StepPin, LOW);
          delayMicroseconds(500);
        }

          //bluetooth dan 9 değeri gönderilirse bunları yap yapılacak işlem

      }
    if(mesaj == '0'){      //PİN ARTARSA LED YAKMA, KORNA ÇALMA vb. EK FONKSİYONLAR İÇİN DEVAM EDEİLEBİLİR.

        //bluetooth dan 0 değeri gönderilirse bunları yap yapılacak işlem



      }

      // if(mesaj == "...") olarak ek fonksiyonlar eklenebilir.
           
    }
  

}
void yerindesag() { // sağa dönme hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorR1, LOW); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, HIGH); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRE, (hiz - 300)); // Sağ motorun hızı 150

  digitalWrite(MotorL1, LOW); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, HIGH); // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, hiz); // Sol motorun hızı 150
  delay(bekle);


}
void yerindesol() { // sola dönme hareketi için fonksiyon tanımlıyoruz.
  digitalWrite(MotorR1, LOW); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, HIGH); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRE, hiz); // Sağ motorun hızı 150

  digitalWrite(MotorL1, LOW); // Sol motorun ileri hareketi pasif
  digitalWrite(MotorL2, HIGH); // Sol motorun geri hareketi aktif
  analogWrite(MotorLE, (hiz - 300)); // Sol motorun hızı 0 (Motor duruyor)
  delay(bekle);



}
void ileri() { // ileri yönde hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorR1, LOW); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, HIGH); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRE, hiz); // Sağ motorun hızı 150

  digitalWrite(MotorL1, LOW); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, HIGH); // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, hiz); // Sol motorun hızı 150



}


void dur() { // durma hareketi için fonksiyon tanımlıyoruz.
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, LOW);
  digitalWrite(MotorRE, LOW);

  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, LOW);
  digitalWrite(MotorLE, LOW);

}
