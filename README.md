# STM32 Sand Clock Project


## Page content:

Info about Board: [BluePill](#board).

Screens and Library: [LCD5110](#screens).

Accelerometer: [MPU6050](#accelerometer).

[Final Project](#project-review).

[How to use](#how-to-use)


## Board

### In this project we used simple STM32F103C8T6 (a.k.a. BluePill).

![image](https://github.com/user-attachments/assets/676ff7ab-8136-4638-9dca-0ee2d9cbb573)

    Input voltage : 5V
    Operating voltage : 3.3V
    10 Analog inputs
    37 Digital IO pins
    Maximum current per pin : 6mA
    64/128 KB Flash memory
    20KB SRAM memory
    72MHz clock speed
    Support I2C, SPI, UART, CAN, USB communications

We used SPI two times to work with LCD's and I<sup>2</sup>C to comunicate with accelerometer.

### Configurating project:

File -> New -> STM32 Project

Chose STM32F103C8T6 in MCU/MPU Selector

Programming language **C**.

## Screens

### Used simple screens from Nokia 5110

![image](https://github.com/user-attachments/assets/65e82fff-2d46-4426-8f05-ae18295fb2dd)


Display Technology	Dot Matrix LCD
MCU Interface	SPI
Screen Size	1.5 Inch Across
Resolution	84×48 pixels
Operating Voltage	2.7V – 3.3V
Operating Current	50mA max

### Configuration

I requires one SPI (can be unidirectional -- from Master to Slave) and three control pins -- RST, CS, DC. 
That is, a total of 5 to comunicate with BluePill.

![pins-image](https://github.com/user-attachments/assets/ff6e219b-41f9-4c1a-bdca-0036f204e15c)

![Screenshot from 2024-12-12 13-14-05](https://github.com/user-attachments/assets/c9fe6371-0b67-43c0-8d1b-943518d06b55)

All output is by putting two matrices into those screens.

## Accelerometer

### Used cheapest MPU6050

    MEMS 3-aixs accelerometer and 3-axis gyroscope values combined
    Power Supply: 3-5V
    Communication : I2C protocol
    Built-in 16-bit ADC provides high accuracy
    Built-in DMP provides high computational power
    Can be used to interface with other IIC devices like magnetometer
    Configurable IIC Address
    In-built Temperature sensor
  
![image](https://github.com/user-attachments/assets/12b300d6-ff42-49cb-aa64-62bc5ff5882d)

![image](https://github.com/user-attachments/assets/73c9eb93-8fab-4720-8c96-166aed508242)

![Screenshot from 2024-12-12 13-18-54](https://github.com/user-attachments/assets/58612d03-cd73-4183-a903-2f04cf2be4ae)

![Screenshot from 2024-12-12 13-19-14](https://github.com/user-attachments/assets/1eddb2ca-2452-4bb8-b5f5-bf432a5f2864)

Here used only _**Z-Accel**_.

## Final Project

![image](https://github.com/user-attachments/assets/d2f23fd6-fddc-4ce8-bb48-55d65f83f7b1)

![image](https://github.com/user-attachments/assets/d6a864ec-1678-4c84-992f-af84ccb757a0)

## How to use

To program BluePill you will need to have STLink-V2 and STM32CubeProgrammer [(link)](https://www.st.com/en/development-tools/stm32cubeprog.html)

![image](https://github.com/user-attachments/assets/e02b2093-7913-46af-96ca-cd106e3ded33)

Connect Stlink to BluePill like this:

![image](https://github.com/user-attachments/assets/4008324b-95e1-4218-a258-720284eba9c8)

Than plug it into pc.

Open STM32CubeProgrammer -> Click "Connect" -> Left bar "Erasing & Programming" -> click "Browse" and find SandClock.elf file you downloaded from [here](https://github.com/f1rset/SandClock/releases).
-> click "Start Programming".
After programming was done you will see how sand is ticking from one screen to another.





