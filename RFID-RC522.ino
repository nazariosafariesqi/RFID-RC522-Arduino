#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 53
#define RST_PIN 49

MFRC522 Kartu(SS_PIN, RST_PIN);
void setup(){
  Serial.begin(9500);
  SPI.begin();
  Kartu.PCD_Init();
  Serial.println("Put your card to the reader ... ");
}

void loop(){
  if(Kartu.PICC_IsNewCardPresent())
  {
    if(Kartu.PICC_ReadCardSerial()){
      Serial.print("Tag UID :");
  String content= "";
  byte letter;
  for (byte i = 0; i < Kartu.uid.size; i++) 
  {
     Serial.print(Kartu.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(Kartu.uid.uidByte[i], HEX);
     content.concat(String(Kartu.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(Kartu.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "83 23 38 BB") // Ganti UID card yang ingin diberikan akses
  {
    Serial.println("Authorized access");
    Serial.println();
    delay(5000);
  }
 
 else   {
    Serial.println(" Access denied");
    delay(1000);
  }
    }
    Serial.println();
    Kartu.PICC_HaltA();
  }
}
