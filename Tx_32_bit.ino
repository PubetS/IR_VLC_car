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
      irsend.sendSony(0x34895725, 32); //881415973
      Serial.println("881415973");
      delay(30);
      } 
 
  else if (digitalRead(6) == LOW){
      irsend.sendSony(0x56874159, 32); //1451704665
      Serial.println("1451704665");
      delay(30);
      } 
 
  else if (digitalRead(8) == LOW){
      irsend.sendSony(0x65467823, 32); //1699117091
      Serial.println("1699117091");
      delay(30);
      } 

  
      
   delay(1);
  
  }