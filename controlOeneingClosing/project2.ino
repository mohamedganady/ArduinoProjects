#define BLYNK_TEMPLATE_ID "TMPL6lukEIGGz"
#define BLYNK_TEMPLATE_NAME "RA1"
#define BLYNK_AUTH_TOKEN "kvTVu_AvgMUNvW2v3uLZBeoNSrUvofDA"

#define BLYNK_PRINT      Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include<Servo.h>

Servo servo1;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Ra1";   
char pass[] = "123456789";  

const unsigned long timerInterval = 10 * 60 * 60 * 1000; 

unsigned long previousMillis = 0;


void setup()
{
  Serial.begin(9600);
  servo1.attach(D5);   
  Blynk.begin(auth, ssid, pass);

  delay(2000);    //delay 2 seconds
}

void loop() 
{
  Blynk.run();

  // Get the current time
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= timerInterval) {
    servo1.write(90);
    // Update the previous activation time
    previousMillis = currentMillis;
  }
  
}

// Blynk virtual pin handler for servo control
BLYNK_WRITE(V1)
{
  int angle = param.asInt();
  servo1.write(angle);
  Blynk.virtualWrite(V1, angle);
}






