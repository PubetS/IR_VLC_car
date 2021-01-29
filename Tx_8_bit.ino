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
      irsend.sendSony(0xca,8); //202
      Serial.println("202");
      delay(30);
      } 
 
  else if (digitalRead(6) == LOW){
      irsend.sendSony(0xac, 8); //172
      Serial.println("172");
      delay(30);
      } 
 
  else if (digitalRead(8) == LOW){
      irsend.sendSony(0xaf, 8); //175
      Serial.println("175");
      delay(30);
      } 


 
   delay(1);
  
  }