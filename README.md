PWM example for students to work with a Full Bridge driver. 

Using the PwmOut API and the OSEPP MTD-01 full bridge driver.
 
Hardware
L432KC or similar with PWM capable outputs.
LED and 220 Ohm resistor.
For testing full bridge driver: OSEPP MTD-01 + DC motor.
The motor maximum 46 V and 2 A continuous 3 A 100 microseconds in starting.
 
Connect:
L432KC D3 -- 220 Ohm -- LED+ 
L432KC GND -- LED-

The MTD-01 digital inputs recognize 3,3 V as HIGH although logic operating voltage is 5 V. 
ENA is the enable signal and is used for pwm speed control.
L432KC D3 -- OSEPPMTD01 ENA
L432KC D9 -- OSEPPMTD01 In1
L432KC D10 -- OSEPPMTD01 In2
L432KC 5V -- OSEPPMTD01 5V
L432KC GND -- OSEPPMTD01 GND
 
Disconnect the jumper JP1 on the MTD-01 !!!!!
12V power -- OSEPPMTD01 VCC
0V power -- OSEPPMTD01 GND

MOTOR + -- OSEPPMTD01 OUT1
MOTOR - -- OSEPPMTD01 OUT2

There are a number of other full bridge DC motor control boards available. 
Please check the digital input functions before trying with other than the OSEPP MTD-01. 

The software is provided under Apache-2.0 license. 