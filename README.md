# MovingCar-Project-Atmega32-Sprints
This project is the Second project for the Automotive bootcamp organized by sprints, this project is developed by team 6

## Team Members
- Ahmed Mohamed Hesham
- Momen Hassan
- Ahmed Atef

## About Project 
This project is controlling a 4 DC motors toy car using Atmega32 and controling it's speed by a generated pwm using the normal mode of the timer.

It uses external interrupts too, to sudden stop the project.

It consists of four layers:
### 1- APP 
This layer is resbonsible for integerating application modules and peripheral to perform project functionality via using their APIs
 
### 2- ECUAL
In this layer modules' drivers are developed which are buttons' driver, LEDs' driver, motors' driver.

This layer is like a middle junction between application layer and microcontroller abstraction layer 

### 3- MCAL
In this layer peripherals' drivers are developed which are DIO's driver, timers' driver, external interrupts' driver.

### 4- SERVICE
This layer consists of files.h which will serve the main three layers while developing, like it has important data types' type defs, and bit manipulation macros like functions 

---


