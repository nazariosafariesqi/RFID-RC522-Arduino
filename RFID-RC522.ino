#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 53
#define RST_PIN 49

MFRC522 Kartu(SS_PIN, RST_PIN);
void setup(){
  Serial.begin(9600);
  SPI.begin();
  Kartu.PCD_Init();
  Serial.println("Put your card to the reader ... ");
}

void loop(){
  if(Kartu.PICC_IsNewCardPresent()){
    if(Kartu.PICC_ReadCardSerial()){
      Serial.print("Tag UID:");
      for(byte i = 0; i < mfrc522.uid.size; i++){
          Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
          Serial.print(mfrc522.uid.uidByte[i], HEX);
    }
    Serial.println();
    Kartu.PICC_HaltA();
  }
}
}
