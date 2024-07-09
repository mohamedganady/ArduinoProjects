#define BLYNK_TEMPLATE_ID "TMPL6CKzzWFEQ"
#define BLYNK_TEMPLATE_NAME "Gas Leakage"
#define BLYNK_AUTH_TOKEN "BFhwV1xykWSqXodxLFLH_bcjuV2BXS6F"

#define BLYNK_PRINT    Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "pc";  
char pass[] = "12341234";  

// Motor pin configuration
#define motor1_pin1  D2          // GPIO 0
#define motor1_pin2  D1          // GPIO 2
#define motor2_pin1  D3          // GPIO 5
#define motor2_pin2  D4          // GPIO 4

// Gas sensor pin configuration
const int gas_sensor = A0; 
// Buzzer 
const int buzzer_pin = D8;

// Motor speed
const int motor_speed = 90;

// Define gas threshold for turning off the robot
const int gas_threshold = 500;

BlynkTimer timer;   

void setup() {
  // Initialize motor pins as output
  pinMode(motor1_pin1, OUTPUT);
  pinMode(motor1_pin2, OUTPUT);
  pinMode(motor2_pin1, OUTPUT);
  pinMode(motor2_pin2, OUTPUT);
  pinMode(buzzer_pin, OUTPUT);

  // Serial communication for debugging
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  timer.run();
  int gas_value = analogRead(gas_sensor);
  Blynk.virtualWrite(V1, gas_value); 

  if ( gas_value > gas_threshold) {
  Blynk.logEvent("gas_alart","Gas Leakage Detected");
  // Gas detected, turn off the robot
  stop();
  activateBuzzer();
  Serial.print(gas_value);
  
}else{
  // Move in a square motion
  Serial.print(gas_value);
  moveForward();
  delay(1000);
  stop();
  delay(200);
  turnRight();
  delay(400);

  moveForward();
  delay(2000);
  stop();
  delay(200);
  turnRight();
  delay(400);

  moveForward();
  delay(2000);
  stop();
  delay(200);
  turnRight();
  delay(400);

  moveForward();
  delay(2000);
  stop();
  delay(200);
  turnRight();
  delay(400);

  // Gas detection
  deactivateBuzzer();
}
  
}

void moveForward() {
  digitalWrite(motor1_pin1, HIGH);
  digitalWrite(motor1_pin2, LOW);
  digitalWrite(motor2_pin1, HIGH);
  digitalWrite(motor2_pin2, LOW);
  analogWrite(motor1_pin1, motor_speed);
  analogWrite(motor2_pin1, motor_speed);
}

void turnRight() {
  digitalWrite(motor1_pin1, LOW);
  digitalWrite(motor1_pin2, HIGH);
  digitalWrite(motor2_pin1, LOW);
  digitalWrite(motor2_pin2, LOW);
  analogWrite(motor1_pin1, motor_speed );
  analogWrite(motor2_pin1, motor_speed );
}

void stop() {
  digitalWrite(motor1_pin1, LOW);
  digitalWrite(motor1_pin2, LOW);
  digitalWrite(motor2_pin1, LOW);
  digitalWrite(motor2_pin2, LOW);
}

void activateBuzzer() {
  digitalWrite(buzzer_pin, HIGH);
}

void deactivateBuzzer() {
  digitalWrite(buzzer_pin, LOW);
}