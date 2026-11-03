
# IoT-Based Smart Auto-Shutdown for Broken LT Lines

## Project Overview

We are a team of three engineering students working on an IoT-based system designed to identify faults in low-voltage (LT) electrical line sections, isolate the affected section, and provide alerts.

The project aims to explore how IoT technology can support electrical line monitoring and improve safety.

## Problem Statement

Broken or fallen electrical lines can create dangerous situations for people and surrounding areas. Identifying the affected line section and isolating it quickly is an important safety challenge.

Our project explores a prototype approach to address this problem.

## Proposed Solution

The proposed system focuses on:

- Monitoring simulated electrical line sections.
- Detecting a change in the monitored input condition.
- Identifying the affected section.
- Switching OFF the corresponding relay.
- Activating a buzzer alert.
- Displaying fault information through the Blynk IoT platform.

## Current Prototype

We have developed an initial low-voltage prototype using:

- NodeMCU ESP8266
- 4-channel relay module
- Three bulbs representing line sections
- Buzzer
- Wi-Fi connectivity
- Blynk IoT platform
- Power supply and connecting wires

## Working Principle

1. The NodeMCU monitors the input conditions of the simulated line sections.
2. A disconnection changes the monitored input condition.
3. The controller identifies the affected section based on the input.
4. The corresponding relay switches OFF.
5. The other simulated sections can remain ON.
6. The buzzer provides an alert.
7. Fault information is communicated through the Blynk IoT platform.

## Project Development Status

- [x] Problem identification
- [x] Initial prototype development
- [ ] Hardware integration and testing
- [ ] System improvements
- [ ] Further development of fault detection
- [ ] AI/ML integration (planned future phase)
- [ ] Real-world feasibility study

## Future Scope

We plan to explore:

- Improved fault detection and section identification.
- AI/ML-based anomaly detection.
- Better monitoring and alert mechanisms.
- Real-world implementation feasibility.
- Integration with suitable electrical protection equipment.

## Important Safety Note

This is an educational, low-voltage prototype. It is not connected to live LT electrical lines and is not certified for real-world electrical protection or deployment.

Real-world implementation would require suitable industrial-grade sensors, certified protection equipment, extensive testing, and validation by qualified electrical professionals. AI/ML would be an additional monitoring capability, not a replacement for independent electrical protection systems.

## Technologies Used

- Embedded Systems
- NodeMCU ESP8266
- Internet of Things (IoT)
- Blynk IoT
- Arduino IDE
- C/C++ (Arduino programming)

- 
## Project Gallery

### 1. Prototype Overview

![Prototype Overview](images/prototype%20overview.jpeg)

### 2. Hardware Connections

![Hardware Connections](images/hardware%20connections.jpeg)

### 3. Working Workflow

![Working Workflow](images/work%20flow.jpeg)


## Project Team

Developed by a team of three 
1.G.RITHIKA
2.K.PRIYADHARSHINI
3.A.ISWARIALAKSHMI

---

*This project is currently under development. Further improvements and testing are ongoing.*
