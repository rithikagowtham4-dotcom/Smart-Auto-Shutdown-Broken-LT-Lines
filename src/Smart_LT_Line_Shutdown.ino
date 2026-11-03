
/************************************************************
 PROJECT: SMART AUTO-SHUTDOWN FOR BROKEN LT LINES
 CONTROLLER: NodeMCU ESP8266
 PROGRAMMING: C/C++
 IoT PLATFORM: Blynk

 TEAM SIZE: 3 MEMBERS

 DESCRIPTION:
 This prototype monitors three LT-line sections using
 digital inputs. When a wire-cut condition is detected,
 the corresponding relay output is controlled and an
 alert is sent through the Blynk IoT application.

 NOTE:
 This is an educational low-voltage prototype.
************************************************************/

#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL3hmPY4gpe"
#define BLYNK_TEMPLATE_NAME "line cut"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Wi-Fi credentials
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// Input pins
const int POST1_INPUT = D4;
const int POST2_INPUT = D1;
const int POST3_INPUT = D2;

// Output pins
const int POST1_RELAY = D5;
const int POST2_RELAY = D6;
const int POST3_RELAY = D7;
const int COMMON_OUTPUT = D8;

// Previous input states
int previousPost1 = -1;
int previousPost2 = -1;
int previousPost3 = -1;

// Timing
unsigned long previousReadTime = 0;
const unsigned long READ_INTERVAL = 1000;

// Function to process each post condition
void checkPost(
  int currentState,
  int &previousState,
  int relayPin,
  int virtualPin,
  const char* postName
) {
  if (currentState == previousState) {
    return;
  }

  previousState = currentState;

  if (currentState == HIGH) {

    Serial.print("WIRE CUT ");
    Serial.println(postName);

    Blynk.virtualWrite(
      virtualPin,
      "WIRE CUT - " + String(postName)
    );

    Blynk.logEvent(
      "alert",
      "WIRE CUT DETECTED - " + String(postName)
    );

    digitalWrite(relayPin, HIGH);

  } else {

    Serial.print("NORMAL ");
    Serial.println(postName);

    Blynk.virtualWrite(virtualPin, "NORMAL");

    digitalWrite(relayPin, LOW);
  }
}

// Setup
void setup() {

  Serial.begin(9600);

  // Configure input pins
  pinMode(POST1_INPUT, INPUT_PULLUP);
  pinMode(POST2_INPUT, INPUT_PULLUP);
  pinMode(POST3_INPUT, INPUT_PULLUP);

  // Configure output pins
  pinMode(POST1_RELAY, OUTPUT);
  pinMode(POST2_RELAY, OUTPUT);
  pinMode(POST3_RELAY, OUTPUT);
  pinMode(COMMON_OUTPUT, OUTPUT);

  // Initial output states
  digitalWrite(POST1_RELAY, HIGH);
  digitalWrite(POST2_RELAY, HIGH);
  digitalWrite(POST3_RELAY, HIGH);
  digitalWrite(COMMON_OUTPUT, HIGH);

  Serial.println();
  Serial.println("SMART LT LINE SYSTEM STARTING");

  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

// Main loop
void loop() {

  Blynk.run();

  unsigned long currentTime = millis();

  if (currentTime - previousReadTime >= READ_INTERVAL) {

    previousReadTime = currentTime;

    // Read line conditions
    int post1 = digitalRead(POST1_INPUT);
    int post2 = digitalRead(POST2_INPUT);
    int post3 = digitalRead(POST3_INPUT);

    Serial.println("----------------------");

    Serial.print("POST 1: ");
    Serial.println(post1);

    Serial.print("POST 2: ");
    Serial.println(post2);

    Serial.print("POST 3: ");
    Serial.println(post3);

    // Process individual sections
    checkPost(
      post1,
      previousPost1,
      POST1_RELAY,
      V0,
      "POST 1"
    );

    checkPost(
      post2,
      previousPost2,
      POST2_RELAY,
      V1,
      "POST 2"
    );

    checkPost(
      post3,
      previousPost3,
      POST3_RELAY,
      V2,
      "POST 3"
    );

    // Common output control
    if (post1 == LOW &&
        post2 == LOW &&
        post3 == LOW) {

      digitalWrite(COMMON_OUTPUT, HIGH);

    } else {

      digitalWrite(COMMON_OUTPUT, LOW);
    }
  }
}
