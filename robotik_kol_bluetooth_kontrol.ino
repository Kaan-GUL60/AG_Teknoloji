
//pin tanımlamaları

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  //pin mode tanımlamaları

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    char mesaj = Serial.read();
    Serial.println(mesaj);

    if(mesaj == '1'){   //ARABA DÜZ GİDECEK kodlarınız yaz buradaki if'in içine
      //bluetooth dan 1 değeri gönderilirse bunları yap yapılacak işlem


      }
    if(mesaj == '2'){   //ARABA DURACAK kodlarınız yaz buradaki if'in içine
        //bluetooth dan 2 değeri gönderilirse bunları yap yapılacak işlem


      }
    if(mesaj == '3'){    //ARABA SAĞA DÖNECEK kodlarınız yaz buradaki if'in içine
        //bluetooth dan 3 değeri gönderilirse bunları yap yapılacak işlem


      }
    if(mesaj == '4'){    //ARABA SOLA DÖNECEK kodlarınız yaz buradaki if'in içine
    
        //bluetooth dan 4 değeri gönderilirse bunları yap yapılacak işlem

      }
    if(mesaj == '5'){     //KOLU KENDİ ETRAFINDA DÖNDER kodlarınız yaz buradaki if'in içine
     
       //bluetooth dan 5 değeri gönderilirse bunları yap yapılacak işlem

      }
    if(mesaj == '6'){     //KOLU AŞAĞI İNDİR kodlarınız yaz buradaki if'in içine
        //bluetooth dan 6 değeri gönderilirse bunları yap yapılacak işlem



      }
    if(mesaj == '7'){     //KOLU YUKARI KALDIR kodlarınız yaz buradaki if'in içine
        //bluetooth dan 7 değeri gönderilirse bunları yap yapılacak işlem


      }
    if(mesaj == '8'){     //EL İLE TOPU TUTMA kodlarınız yaz buradaki if'in içine
      //bluetooth dan 8 değeri gönderilirse bunları yap yapılacak işlem



      }
    if(mesaj == '9'){     // EL İLE TOPU BIRAKMA kodlarınız yaz buradaki if'in içine


          //bluetooth dan 9 değeri gönderilirse bunları yap yapılacak işlem

      }
    if(mesaj == '0'){      //PİN ARTARSA LED YAKMA, KORNA ÇALMA vb. EK FONKSİYONLAR İÇİN DEVAM EDEİLEBİLİR.

        //bluetooth dan 0 değeri gönderilirse bunları yap yapılacak işlem



      }

      // if(mesaj == "...") olarak ek fonksiyonlar eklenebilir.
           
    }
  

}
