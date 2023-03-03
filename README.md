# Introduction

This is my journey of building a turntable. My old one has a few flaws that i want to solve, it doesn't keep constant speed, and its bearing is pretty bad, and my wife doesn't think it fits the theme of our living room. 
So, a new and improved one will be my next project.

problems to solve:
* Needs to keep track of speed.
* Good bearing.
* Fit living room.

The motor will be a 12V dc motor that will adjust speed by comparing its speed with a digital encoder: wdg 40s-1024-ab-h24-l2-100
https://www.hemomatik.se/PDF/Encoder-WDG-40A-1_h.pdf

the bearing will be magnetic for vertical forces, and housing will be made of bearing bronze turned on my lathe, and a 20mm hardened rod.

And the design will be my own, mostly made out of wood and aluminum, limited here by my tools, but wood and aluminum are pretty easy to work with.
color scheme will be Turquoise and dark grey,

# Code

As the project started during my programming courses in school, that is where i started, i built a testbench for the motor and encoder to try my code live. As i never used the RP2040 processor from raspberry this was necessery to test each step.

Functions for the program will be:
1 PWM function to control Motor speed.                                                      DONE
1 Timer to compare motor speed with encoder speed.                                          DONE
1 counter to count encoder pulses.
3 buttons, one for flashing the card and two to speed up or speed down the platter.
more functions might come, like 1 button to save values to eeprom.

![alt text](https://github.com/onderest/turntable/blob/main/Fig1.png?raw=true)

Fig.1 - Testbench

# Turntable base

The design i first wanted was a two level turntable, much like the Kronos Discovery turntable. but i still like the look of a big beefy platter, so after a few designs on paper i decided on a look i really liked.


![alt text](?raw=true)

Fig.3 - design

![alt text](https://github.com/onderest/turntable/blob/main/FigAluparts.png?raw=true)

Fig.3 - alu parts

# Bearing

the bearing i made out of  bearing bronze 50mm roundbar i had at home and a 20mm hardend steel rod.


![alt text](https://github.com/onderest/turntable/blob/main/FigBearging2.png?raw=true)
![alt text](https://github.com/onderest/turntable/blob/main/FigBearing1.png?raw=true)

Fig.4-5 - Bearing


![alt text](https://github.com/onderest/turntable/blob/main/Testfit.png?raw=true)

Fig.6 - Testfit
