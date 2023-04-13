# MovingCar-Project-Atmega32-Sprints
This project is the Second project for the Automotive boot camp organized by Sprints, this project is developed by Team 6

## VIDEO LINK: https://drive.google.com/file/d/1zatvnfsU7jtgb8owXJJvahz6qB2yS4B3/view 

## Team Members
- Ahmed Mohamed Hesham
- Momen Hassan
- Ahmed Atef

## About Project 
This project is controlling a 4 DC motors toy car using Atmega32 and controlling its speed by a generated pwm using the normal mode of the timer.

It uses external interrupts too, to suddenly stop the project.

It consists of four layers:
### 1- APP 
This layer is responsible for integrating application modules and peripherals to perform project functionality via using their APIs
 
### 2- ECUAL
In this layer modules' drivers are developed which are the buttons' driver, LEDs' driver, and motors' driver.

This layer is like a middle junction between the application layer and the microcontroller abstraction layer 

### 3- MCAL
In this layer, peripherals' drivers are developed: DIO's driver, timers' driver, and external interrupts' driver.

### 4- SERVICE
This layer consists of files.h which will serve the main three layers while developing, like it has important data types' type defs, and bit manipulation macros like functions 

---


