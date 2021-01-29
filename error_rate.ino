/*
 *     ForbiddenBit.com
 *     
 *     IR Receiver 
 */
#include <IRremote.h>
 void check_error();
int RECV_PIN = 3;
 int count = 1000;
 int i=0;
 float error = 0.0;
 float error_rate = 0.0;
IRrecv irrecv(RECV_PIN);  

 
decode_results results;
 
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(5,OUTPUT); // Led outputs ...
  pinMode(6,OUTPUT);


}




 
void loop() {

if (irrecv.decode(&results)) {
    Serial.println(results.value);
    delay(30);
    if(i<count)
    {
    check_error();
    }
      irrecv.resume(); // Receive the next value 
}
 

 if (i>=count)
 {
Serial.println(i);
 Serial.println(error);
 Serial.println(count);
 error_rate = (error/count)*100.0;

 Serial.print(error_rate);
 Serial.println(" %");
 delay(100);
 }
}
void check_error()
{
  if(results.value == 1699117091)
    {
      error = error ;
      Serial.print(" Error = ");
      Serial.println(error);
    }
     else 
     {
      error++;
      Serial.print(" Error = ");
      Serial.println(error);
     }
delay(30);
     i++;
      Serial.print(" i = ");
      Serial.println(i);
}

