ESP32 Biometric Attendance System

A fingerprint-based attendance and identity verification system developed during my university studies using ESP32 and an optical fingerprint sensor.

The project demonstrates practical applications of embedded systems, biometric authentication, hardware integration, and serial communication.

Key Features

Fingerprint enrollment and identity verification.

Dual-scan biometric template validation.

Persistent biometric template storage.

Unique user ID assignment (1–127).

Offline fingerprint matching.

UART2 hardware communication.

Arabic Serial Monitor interface.

Basic error handling.

System Architecture

flowchart TD
    A[User Fingerprint] --> B[Fingerprint Sensor]
    B <--> C[Local Biometric Storage]
    B <-->|UART2| D[ESP32]
    D --> E{Verification Result}
    E -->|Matched| F[Display Student ID]
    E -->|Not Matched| G[Unknown Fingerprint]

Technology Stack

Technology

Purpose

ESP32

Embedded processing

Optical Fingerprint Sensor

Biometric authentication

Arduino IDE

Development environment

C/C++

Embedded programming

Adafruit Fingerprint Library

Sensor integration

UART2

Serial communication

Hardware Wiring

Fingerprint Sensor

ESP32

Red – VCC

3.3V

Black – GND

GND

Yellow – TX

GPIO 16 (RX)

White – RX

GPIO 17 (TX)

Communication Settings

Serial Monitor Baud Rate: 115200

Fingerprint Sensor Baud Rate: 57600

Hardware Serial: UART2

Serial Configuration: 8N1

Operating Modes

Fingerprint Enrollment

Captures two fingerprint scans, validates their consistency, generates a biometric template, and stores it in the sensor's internal memory with a unique user ID.

Attendance Verification

Scans fingerprints, searches stored biometric templates, and displays the matched student ID or an unknown fingerprint message through the Serial Monitor.

Required Libraries & Tools

Arduino IDE

Adafruit Fingerprint Sensor Library

ESP32 by Espressif Systems

Source Code

File

Function

enrollment.ino

Fingerprint enrollment and storage

attendance.ino

Fingerprint matching and attendance verification

Getting Started

Install Arduino IDE.

Install the ESP32 board package.

Install the Adafruit Fingerprint Sensor Library.

Verify the sensor's voltage requirements and connect the hardware.

Upload the enrollment sketch and register fingerprints.

Upload the attendance sketch.

Open Serial Monitor at 115200 baud.

Cybersecurity Concepts

Biometric Authentication

Identity Verification

Identity and Access Management (IAM)

Something You Are

Skills Applied

Embedded Systems Programming

C/C++ Programming

Hardware Integration

Biometric Authentication

Serial Communication

Data Processing

Troubleshooting and Debugging

System Architecture
