#include "arduino_secrets.h"
#include <DHT.h>
#include "WiFi.h"
#include "thingProperties.h"

#define DHTPIN 2     // Define the pin where DHT11 is connected
#define DHTTYPE DHT11 // Define the type of DHT sensor

#define PULSE_PIN 4  // Define the pin where the pulse sensor is connected
#define ECG_LO_NEG_PIN 34 // Define the pin where LO- of AD8232 is connected
#define ECG_LO_POS_PIN 32 // Define the pin where LO+ of AD8232 is connected
#define ECG_OUTPUT_PIN 35  // Define the analog pin where AD8232 is connected for output

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor

void onEcgChange() {
  // Add your code here to act upon ECG change
}

void onPulseChange() {
  // Add your code here to act upon Pulse change
}

void onTempChange() {
  // Add your code here to act upon Temp change
}

void setup() {
  Serial.begin(9600);
  delay(1500);

  dht.begin(); // Start DHT sensor
  pinMode(PULSE_PIN, INPUT); // Set pulse sensor pin as input
  pinMode(ECG_LO_NEG_PIN, INPUT); // Set LO- pin as input
  pinMode(ECG_LO_POS_PIN, INPUT); // Set LO+ pin as input
  pinMode(ECG_OUTPUT_PIN, INPUT);   // Set AD8232 output pin as input

  initProperties();

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();

  float temperature = dht.readTemperature();
  int pulseValue = digitalRead(PULSE_PIN);
  int ecgLoNegValue = digitalRead(ECG_LO_NEG_PIN);
  int ecgLoPosValue = digitalRead(ECG_LO_POS_PIN);
  int ecgOutputValue = analogRead(ECG_OUTPUT_PIN);

  temp = temperature;
  pulse = pulseValue;
  ecg = ecgOutputValue; // Assuming ecg is of type CloudHeartRate
}