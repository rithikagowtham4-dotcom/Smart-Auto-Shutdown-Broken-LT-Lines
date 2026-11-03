
# Working Principle

## 1. System Initialization
The NodeMCU ESP8266 starts and initializes the connected hardware components and Wi-Fi communication.

## 2. Line Section Monitoring
The system monitors the input conditions of three simulated LT line sections.

## 3. Fault Detection
When a disconnection occurs in a simulated section, the monitored input condition changes.

## 4. Fault Section Identification
The NodeMCU determines which simulated section has experienced the change.

## 5. Automatic Isolation
The corresponding relay is switched OFF to disconnect the affected simulated section. The other sections can remain ON.

## 6. Alert Notification
The buzzer is activated to provide an audible alert. The fault status is also communicated through the Blynk IoT platform using Wi-Fi.

## Demonstration Outcome

The prototype demonstrates the basic concept of identifying an affected simulated section, switching its relay OFF, and providing an alert.

**Note:** This is a low-voltage educational prototype. Its operation does not establish reliable detection of all real-world broken LT conductors.
