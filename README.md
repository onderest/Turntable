# Introduction

This is my journey of building a turntable. My old one has a few flawes that i want to solve, it doesn't keep constant speed, and its bearing is pretty bad and my wife doesn't think it fits the theme of our livingroom. 
So a new and improoved one will be my next project.

problems to solve:
* Needs to keep track of speed.
* Good bearing.
* Fit livingroom.

The motor will be a 12V dc motor that will adjust speed by comparing its speed with a digital encoder: wdg 40s-1024-ab-h24-l2-100
https://www.hemomatik.se/PDF/Encoder-WDG-40A-1_h.pdf

the bearing will be magnetic for vertical forces, and housing will be made of bearing bronze turned on my lathe, and a 20mm hardned rod.

And the design will be my own, mostly made out of wood and aluminium, limited here by my tools, but wood and aluminium is pretty easy to work with.
color scheme will be Turqouse and dark grey,

# Code

As the project started during my programming courses in school, that is where i started, i built a testbench for the motor and encoder to try my code live. As i never used the RP2040 processor from raspberry this was nececerry to test each step.

Functions for the program will be:
1 PWM function to control Motor speed.                                                      DONE
1 Timer to compare motor speed with encoder speed.                                          DONE
1 counter to count encoder pulses.
3 buttons, one for flashing the card and two to speed up or speed down the platter.
moore functions might come, like 1 button to save values to eeprom.

![alt text](https://github.com/onderest/turntable/blob/main/Fig1.png?raw=true)

Fig.1 - Testbench

# Turntable base

The design i first wanted was a two level turntable, much like the Kronos Discovery turntable. but i still like the look of a big beefy platter, so after a few designs on paper i decided on a look i really liked.

![alt text](?raw=true)

Fig.2 - design


# Bearing

the bearing i made out of  bearing bronze 50mm roundbar i had at home and a hardent rod.


![alt text](https://github.com/onderest/turntable/blob/main/Fig3.png?raw=true)
![alt text](https://github.com/onderest/turntable/blob/main/Fig2.png?raw=true)

Fig.3 - Bearing
