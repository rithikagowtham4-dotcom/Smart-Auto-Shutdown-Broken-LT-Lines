
# Prototype Hardware Components

This document lists the hardware and platforms used in our initial prototype.

| Component | Purpose |
|---|---|
| NodeMCU ESP8266 | Main controller for monitoring input conditions |
| 4-channel relay module | Controls the simulated line sections |
| Three bulbs | Represent three separate LT line sections |
| Buzzer | Provides an audible fault alert |
| Wi-Fi | Enables communication with the IoT platform |
| Blynk IoT | Displays system status and fault information |
| Power supply | Supplies power to the prototype |
| Connecting wires | Connect the hardware components |

## Prototype Setup

The prototype uses three simulated line sections. The NodeMCU monitors their input conditions. When a disconnection is detected in a section, the controller switches OFF its corresponding relay and activates the alert mechanism.

The setup demonstrates the basic concept using a low-voltage educational model.

## Safety

This prototype is not connected to live electrical distribution lines. It is not certified or suitable for real-world electrical protection.
