#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

const char* ssid     = "SSID"; //Set Wifi SSID
const char* password = "Pass";//Set Wifi password

char thingSpeakAddress[] = "api.thingspeak.com";    // Host ของ thingspeak ไม่ต้องแก้ไข
String writeAPIKey  = "API";  //API Key ที่เราจำไว้ ในขั้นต้นเมื่อกี้
WiFiClient client;


int LED_1=D4;
int LED_2=D5;
String car1 = "0";
String car2 = "0";
String car3 = "0";

void setup() {
  Serial.begin(9600);
  delay(10);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  pinMode(D0,INPUT);
  pinMode(D1,INPUT);
  pinMode(D2,INPUT);
  pinMode(D3,INPUT);
  pinMode(LED_1,OUTPUT); // Led outputs ...
  pinMode(LED_2,OUTPUT);
}

void loop() {
  
 if(digitalRead(D0)==1){
   car1 ="1";
   car2 ="0";
   car3 ="0";
   Serial.println("car_1 Access!!");
   digitalWrite(LED_1,HIGH);
   digitalWrite(LED_2,LOW);
   delay(100);
 }

 else if(digitalRead(D1)==1){
   car1 ="0";
   car2 ="1";
   car3 ="0";
   Serial.println("car_2 Access!!");
   digitalWrite(LED_1,HIGH);
   digitalWrite(LED_2,LOW);
   delay(100);
 }

 else if(digitalRead(D2)==1){
   car1 ="0";
   car2 ="0";
   car3 ="1";
    Serial.println("car_3 Access!!");
    digitalWrite(LED_1,HIGH);
    digitalWrite(LED_2,LOW);
    delay(100);
  }

  else {
   car1 ="0";
   car2 ="0";
   car3 ="0";
    Serial.println("No Car Access");
    digitalWrite(LED_1,HIGH);
    digitalWrite(LED_2,LOW);
    delay(100);
  }

  

  String data = "field1=" + car1 + "&field2=" + car2 + "&field3=" + car3; // แปลงเป็น string ให้หมดนะครับเพื่อจะส่งเเล้วนะครับ
if(digitalRead(D3)==1){
  if (client.connect(thingSpeakAddress, 80)) {
    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: "+writeAPIKey+"\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(data.length());
    client.print("\n\n");
    client.print(data); 

  }
}
delay(1000);
}