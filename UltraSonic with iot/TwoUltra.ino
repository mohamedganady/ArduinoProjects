#define BLYNK_TEMPLATE_ID "TMPL6rxDKelDb"
#define BLYNK_TEMPLATE_NAME "UltraProject"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

/*ultrasonic1  conection to pin d2 and pin d1*/
#define trig            D2
#define echo            D1
/*ultrasonic2  conection to pin d2 and pin d1*/
#define trig2           D7
#define echo2           D8

long duration , duration2;
int distance , distance2;


// You should get Auth Token in the Blynk App.

char auth[] = "UpM1rhL9JSENb4qI_izqGkSgt_Enm3KA";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "B.";
char pass[] = "11111111";

BlynkTimer timer;
WidgetLCD lcd(V1);


void setup() {
  // Debug console
  pinMode(trig, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echo, INPUT);   // Sets the echoPin as an Inpu
  pinMode(trig2, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echo2, INPUT);   // Sets the echoPin as an Inpu
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  // Setup a function to be called every second
}

void loop() {
  Blynk.run();
  digitalWrite(trig, LOW);  // Makes trigPin low
  delayMicroseconds(2);     // 2 micro second delay

  digitalWrite(trig, HIGH);  // tigPin high
  delayMicroseconds(10);     // trigPin high for 10 micro seconds
  digitalWrite(trig, LOW);   // trigPin low

  duration = pulseIn(echo, HIGH);   //Read echo pin, time in microseconds
  distance = duration * 0.034 / 2;  //Calculating actual/real distance

  Serial.print("Distance1 = ");  //Output distance on arduino serial monitor
  Serial.println(distance);
  Blynk.virtualWrite(V1, distance);



  digitalWrite(trig2, LOW);  // Makes trigPin low
  delayMicroseconds(2);     // 2 micro second delay

  digitalWrite(trig2, HIGH);  // tigPin high
  delayMicroseconds(10);     // trigPin high for 10 micro seconds
  digitalWrite(trig2, LOW);   // trigPin low

  duration2 = pulseIn(echo2, HIGH);   //Read echo pin, time in microseconds
  distance2 = duration2 * 0.034 / 2;  //Calculating actual/real distance

  Serial.print("Distance2 = ");  //Output distance on arduino serial monitor
  Serial.println(distance2);
  Blynk.virtualWrite(V0, distance2);

  delay(1000);  /*mile second*/
}