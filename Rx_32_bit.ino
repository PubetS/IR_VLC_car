#include <IRremote.h>
#include "LCDIC2.h"
#include <Servo.h>
Servo myservo;
int pos = 0; 

void door_open();
void door_close();

int RECV_PIN = 3;
IRrecv irrecv(RECV_PIN);
decode_results results; 

LCDIC2 lcd(0x3F, 16, 2);


int door_state = 0;
  

 

void setup()
{
  myservo.attach (7);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver

  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);

 if (lcd.begin())
 lcd.setCursor(0,0);
 lcd.print("VLC ");
 lcd.setCursor(0,1);
 lcd.print("DATA RECEIVER ");
 delay(2000);

 lcd.setCursor(0,0);
 lcd.print("NO MESSAGE ");
 lcd.setCursor(0,1);
 lcd.print(" WAITING..."); 
 myservo.write(90); 
 
}

void loop()

{

if (irrecv.decode(&results)) {
    Serial.println(results.value);
 
    if(results.value ==  1451704665)   //  881415973)
     {
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,HIGH);

      lcd.clear();
      Serial.println(" Car No 1 Accress");
      lcd.setCursor(0,0);
      lcd.print("Car No 1 Accress MEMBER!");
      lcd.setCursor(0,1);
      lcd.print("> > WELCOME! < <");
      lcd.clear();
      delay(2000);

      lcd.setCursor(0,0);
      lcd.print("door opening");
      door_open();
      delay(10000);

      lcd.clear();
      lcd.print("door close");
      door_close();
      
      lcd.setCursor(0,0);
      lcd.print("NO MESSAGE ");
      lcd.setCursor(0,1);
      lcd.print(" WAITING...");
      }
 
     else if(results.value ==  881415973)       //1451704665)
     {
      digitalWrite(8,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(10,LOW);
      digitalWrite(11,HIGH);

      lcd.clear(); 
      Serial.println(" Car No 2 Accress");
      lcd.setCursor(0,0);
      lcd.print("Car No 2 Accress MEMBER!");
      lcd.setCursor(0,1);
      lcd.print("> > WELCOME! < <");
      delay(2000);

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("door opening");
      door_open();
      delay(10000);

      lcd.clear();
      lcd.print("door close");
      door_close();
      
      lcd.setCursor(0,0);
      lcd.print("NO MESSAGE ");
      lcd.setCursor(0,1);
      lcd.print(" WAITING...");
      }
 
     else if(results.value == 1699117091)  //1699117091 )
     {
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);

      lcd.clear ();
      Serial.println(" Car No 3 Accress");
      lcd.setCursor(0,0);
      lcd.print("Car No 3 Accress MEMBER!");
      lcd.setCursor(0,1);
      lcd.print("> > WELCOME! < <");
      delay(2000);

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("door opening");
      door_open();
      delay(10000);

      lcd.clear();
      lcd.print("door close");
      door_close();
      lcd.setCursor(0,0);
      lcd.print("NO MESSAGE ");
      lcd.setCursor(0,1);
      lcd.print(" WAITING...");
     }
     

     else{
     digitalWrite(8,LOW);
     digitalWrite(9,LOW);
     digitalWrite(10,LOW);
     digitalWrite(11,LOW);
     lcd.setCursor(0,0);
     lcd.print("NO.");
     lcd.print(" WAIT!"); 
     lcd.setCursor(0,1);
     lcd.print("<< NOT MEMBER >>");
     myservo.write(90); 
     }

    irrecv.resume(); // Receive the next value
  }

  delay(100);
}

void door_open()
{

     for (pos = 90; pos >=35 ; pos -= 1) { // เปลี่ยนจาก 0 ไปเป็น 180 องศา
     myservo.write(pos); // บอก servo ให้ไปในตำแหน่งตามตัวแปร ‘pos’
      
Serial.println(" Door openning");
delay(50);
}

delay(100);
  Serial.println(" Door opened");
delay(100);
}


void door_close()
{
          for (pos = 35; pos <= 90; pos += 1) { 
          myservo.write(pos); 
          Serial.println(" Door closing");
	  digitalWrite(8,LOW);
          digitalWrite(9,LOW);
          digitalWrite(10,LOW);
          digitalWrite(11,HIGH);
          delay(200); 
	  digitalWrite(11,LOW);
          }

     delay(100);
Serial.println(" Door closed");
delay(100);
}