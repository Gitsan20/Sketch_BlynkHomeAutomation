/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "YOUR BLYNK_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR BLYNK_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "YOUR BLYNK_AUTH_TOKEN"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Your SSID";
char pass[] = "Your Password";

// Define the relay pins
const int relayPin1 = 5;  // Replace with the actual GPIO pin connected to relay 1
const int relayPin2 = 4;  // Replace with the actual GPIO pin connected to relay 2
const int relayPin3 = 14;  // Replace with the actual GPIO pin connected to relay 3
const int relayPin4 = 12;  // Replace with the actual GPIO pin connected to relay 4

BlynkTimer timer;

void setupRelayPins()
{
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  pinMode(relayPin3, OUTPUT);
  pinMode(relayPin4, OUTPUT);
  
  // Initial state: all relays off+++++/
  digitalWrite(relayPin1, HIGH);
  digitalWrite(relayPin2, HIGH);
  digitalWrite(relayPin3, HIGH);
  digitalWrite(relayPin4, HIGH);
}

// Blynk callback for V1 (Switch 1)
BLYNK_WRITE(V1)
{
  int relayState = param.asInt();
  digitalWrite(relayPin1, relayState);
}

// Blynk callback for V2 (Switch 2)
BLYNK_WRITE(V2)
{
  int relayState = param.asInt();
  digitalWrite(relayPin2, relayState);
}

// Blynk callback for V3 (Switch 3)
BLYNK_WRITE(V3)
{
  int relayState = param.asInt();
  digitalWrite(relayPin3, relayState);
}

// Blynk callback for V4 (Switch 4)
BLYNK_WRITE(V4)
{
  int relayState = param.asInt();
  digitalWrite(relayPin4, relayState);
}

void setup()
{
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  // Setup relay pins
  setupRelayPins();
}

void loop()
{
  Blynk.run();
  timer.run();
}


