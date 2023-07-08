
/* Bu kodlar  https://elharezmibilgelikevi.com/ sitesi tarafından yazılmıştır. Kodların buradan alınarak video çekilmesi, 
 sitelere konulması, pdf veya başka bir şekilde dağıtılmasına izin yoktur.Para kazanılmayacak bir ortamda eğitim için kullanılabilir. 
Kullanıldığında burada bulunan açıklama bilgisi yazılmak zorundadır. zafer çopur */

#include "deneyap.h"
#include "BluetoothSerial.h"
#define kirmizi D4
#define yesil D9
#define mavi D15  
#define gecelamp D12
#define makinelamp D8
#define motor A0
#include <ServoESP32.h>
Servo mykapi, mypencere;
int servoKapi=D0;
int servoPencere=D1;

BluetoothSerial SerialBT; 
    
char deger;
                   
void setup() {
    SerialBT.begin("SmartHomeDeneyap");
    Serial.begin(9600); 
    mykapi.attach(servoKapi);
    mypencere.attach(servoPencere);
    ledcSetup(0,5000,8);         // kanal 0-15 arası, frekans ledler için =5000 , çözünürlük=8 bit (0-255 arası değer)
    ledcSetup(1,5000,8);
    ledcSetup(2,5000,8);
    ledcAttachPin(kirmizi,0);
    ledcAttachPin(yesil,1);
    ledcAttachPin(mavi,2);
}
void loop() {
    
  if(SerialBT.available()){ 
    deger=SerialBT.read();
    if( deger == '1'){//gece lambası yandı
        digitalWrite(gecelamp,HIGH);
        Serial.println("gece lambası yandı"); 
        }
    if( deger == '2')// gece lambası kapandı
        digitalWrite(gecelamp,LOW);
        Serial.println("gece lambası kapandı");
        }
    if( deger == '3'){//makine açıldı
        digitalWrite(makinelamp,HIGH);
        digitalWrite(motor,HIGH);
        Serial.println("makine açıldı");
        }
    if( deger == '4'){//makine kapandı
        digitalWrite(makinelamp,LOW);
        digitalWrite(motor,LOW);
        Serial.println("makine kapandı");
        }
    if( deger == '5'){//garaj kapı açıldı
        kapi(aç);
        Serial.println("garaj kapı açıldı");
        }
    if( deger == '6'){//garaj kapı kapandı
        kapi(kapa);
        Serial.println("garaj kapı kapandı");
        }
    if( deger == '7'){//boş
        digitalWrite(D0,LOW);
        Serial.println("boş");
        }
    if( deger == '8'){//pencere açıldı
        pencere(aç);
        Serial.println("pencere açıldı");
        }
    if( deger == '9'){//pencere kapandı
        pencere(kapa);
        Serial.println("pencere kapandı");
        }
    if( deger == '0'){//TV açıldı
        RGByak();
        Serial.println("TV açıldı");
        }
    if( deger == 'a'){//TV kapandı
        RGByak();
        Serial.println("TV kapandı");
        }
    if( deger == 'b'){// x müziği açıldı
        digitalWrite(D0,LOW);
        Serial.println("x müziği açıldı");
        }
    if( deger == 'c'){//müzik durduruldu
        digitalWrite(D0,LOW);
        Serial.println("müzik durduruldu");
        }

    delay(500);
    

}

void kapi(String x){
    mykapi.write(0);
    if(x == "aç"){
        for(int pos=0;pos<=180;pos+=1) // pos değeri 0’dan 180 dereceye kadar 1 er derece arttırılır
        {
            mykapi.write(pos);// motor pos değerindeki konuma gider
            delay(15); 
        }
    }
    if(x == "kapa"){
        for(int pos =180;pos>=0;pos-=1) //pos değeri 180’den 0 ‘a kadar 1’er derece azaltılır
        {
            mykapi.write(pos); // motor pos değerindeki konuma gider
            delay(15); 
        }
    }
}
void pencere(String x){
    mypencere.write(0);
    if(x == "aç"){
        for(int pos=0;pos<=180;pos+=1) // pos değeri 0’dan 180 dereceye kadar 1 er derece arttırılır
        {
            mypencere.write(pos);// motor pos değerindeki konuma gider
            delay(15); 
        }
    }
    if(x == "kapa"){
        for(int pos =180;pos>=0;pos-=1) //pos değeri 180’den 0 ‘a kadar 1’er derece azaltılır
        {
            mypencere.write(pos); // motor pos değerindeki konuma gider
            delay(15); 
        }
    }
}
void RGByak(){
    ledcWrite(0,255);
    ledcWrite(1,0);
    ledcWrite(2,0);
    delay(1000);
    ledcWrite(0,0);
    ledcWrite(1,255);
    ledcWrite(2,0);
    delay(1000);
    ledcWrite(0,210);
    ledcWrite(1,105);
    ledcWrite(2,30);
    delay(1000);
}
