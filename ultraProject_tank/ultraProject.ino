#define BLYNK_TEMPLATE_ID "TMPL6rxDKelDb"
#define BLYNK_TEMPLATE_NAME "UltraProject"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

/*ultrasonic1  conection to pin d2 and pin d1*/
#define trig            D2
#define echo            D1


long duration;
int distance ;

char auth[] = "UeGzEcU836pswUIGPrhurYoNlEv5K8px";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Ibn Roshd Educational Holding Co";
char pass[] = "ibnroshd@2030";

BlynkTimer timer;
WidgetLCD lcd(V1);



void setup() {
  // Debug console
  pinMode(trig, OUTPUT);          // Sets the trigPin as an Output
  pinMode(echo, INPUT);           // Sets the echoPin as an Inpu

  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  // Setup a function to be called every second
}

void loop() {
  int max =20;
  Blynk.run();
  digitalWrite(trig, LOW);  // Makes trigPin low
  delayMicroseconds(2);     // 2 micro second delay

  digitalWrite(trig, HIGH);  // tigPin high
  delayMicroseconds(10);     // trigPin high for 10 micro seconds
  digitalWrite(trig, LOW);   // trigPin low

  duration = pulseIn(echo, HIGH);   //Read echo pin, time in microseconds
  distance = max - (duration * 0.034 / 2);  //Calculating actual/real distance

  Serial.print("Distance1 = ");  //Output distance on arduino serial monitor
  Serial.println(distance);
  Blynk.virtualWrite(V1, distance);

  delay(1000);  /*mile second*/
}