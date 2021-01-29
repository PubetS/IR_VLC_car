#include <IRremote.h>
 
IRsend irsend;
 
void setup()
{
  Serial.begin(9600);
  pinMode(5,INPUT_PULLUP); // button 1
  pinMode(6,INPUT_PULLUP); // button 2
  pinMode(8,INPUT_PULLUP);
  
}
 
void loop() {
  
  if (digitalRead(5) == LOW){
      irsend.sendSony(0xD5B6,16); //54710
      Serial.println("54710");
      delay(30);
      } 
 
  else if (digitalRead(6) == LOW){
      irsend.sendSony(0x3B59, 16); //15193
      Serial.println("15193");
      delay(30);
      } 
 
  else if (digitalRead(8) == LOW){
      irsend.sendSony(0xCAE2, 16); //51938
      Serial.println("51938");
      delay(30);
      } 


 
   delay(1);
  
  }