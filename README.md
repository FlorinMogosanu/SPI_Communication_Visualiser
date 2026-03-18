# SPI_Communication_Visualiser  

Hello, and welcome to the SPI Communication Visualizer project!

This project helps you see the invisible data flying around in an SPI bus. We have 4 LEDs, each representing a key line used in SPI communication. The master device (Arduino Nano) sends numbers to the slave device (Arduino Uno) via SPI, and the slave then prints them to the serial monitor.

## Interactive Simulation

You can test the circuit and explore the code directly in your browser before building it. Check out the Tinkercad project here:

[Try the Tinkercad Simulation](https://www.tinkercad.com/things/34kD23fN9Y2-spi-communication-visualiser)

## Demo Video

Want to see it in action? Watch the LEDs flash to represent the live data transfer between the two Arduinos in the video below:

[Watch the Demo Video](https://youtu.be/jSTqgzQati4)

## Hardware Requirements

* Arduino Nano (Master)
* Arduino Uno (Slave)
* 4 LEDs (Red, Yellow, Blue, Green)
* 4 Current-limiting resistors (220 ohm to 330 ohm)
* Jumper wires
* Breadboard

## Pin Mapping and LED Setup

| LED Color | SPI Line | Description | Master Pin | Slave Pin |
|---|---|---|---|---|
| Red | SCK | Clock Signal | D13 | D13 |
| Yellow | CS | Chip Select | D10 | D10 |
| Blue | MOSI | Master Out Slave In | D11 | D11 |
| Green | MISO | Master In Slave Out | D12 | D12 |

## How It Works

The Master pulls the CS line LOW to initiate communication.
It generates a clock signal on the SCK line.
Data is sent bit by bit from the Master to the Slave over the MOSI line.
The Slave reconstructs the byte and prints it to the Serial Monitor.
The Master pulls the CS line HIGH to end the transmission.
Delays are built into the Master code so the human eye can see the LEDs flashing.

## Installation and Usage

1. Connect the Master and Slave pins together as shown in the table.
2. Connect the LEDs and resistors to the corresponding data lines on a breadboard.
3. Connect the common ground between the two Arduinos.
4. Upload the Master code to your Arduino Nano.
5. Upload the Slave code to your Arduino Uno.
6. Open the Serial Monitor for the Arduino Uno and set the baud rate to 9600.
7. Watch the LEDs flash to visualize the data transfer and verify the numbers in the Serial Monitor.
