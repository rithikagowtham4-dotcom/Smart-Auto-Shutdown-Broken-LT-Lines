
# Problem Statement

## Background

Low-voltage (LT) electrical distribution lines are used to supply electricity to residential, commercial, and other areas.

When an electrical line breaks or falls, it can create hazardous situations for people and surrounding areas.

## Problem

Identifying the affected section and isolating it quickly is an important challenge in electrical distribution safety.

This project explores an IoT-based approach to monitor simulated LT line sections, identify a change in the monitored input condition, isolate the affected section, and generate an alert.

## Project Objective

The main objectives are:

- Monitor multiple simulated line sections.
- Identify a change in the input condition.
- Determine the affected simulated section.
- Switch OFF the corresponding relay.
- Generate an audible alert.
- Display fault information through the Blynk IoT platform.

## Current Development

We have developed an initial low-voltage prototype using NodeMCU ESP8266, relay modules, bulbs, a buzzer, and Blynk IoT.

Further development and testing are ongoing.

## Scope and Limitation

The current prototype demonstrates the basic concept only. It does not establish reliable detection of all real-world broken LT lines or guarantee accident prevention.

Real-world implementation requires additional engineering, suitable protection equipment, and validation by qualified professionals.
