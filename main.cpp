/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 *********************************************
 *
 * PWM example using the PwmOut API
 * and the OSEPP MTD-01 full bridge driver
 *
 *********************************************
 *Description: McLab12_OSEPPMTD01_PWM_OS6_tk1
 * Hardware
 * L432KC or similar with PWM capable outputs.
 * The L432KC pin D13 for onboard LED is not PWM capable!
 * LED and 220 Ohm resistor
 * For testing full bridge driver: OSEPP MTD-01 + DC motor
 * The motor maximum 46 V and 2 A continuous 3 A 100 microseconds in starting.
 
 * Connect:
 * L432KC D3 -- 220 Ohm -- LED+ 
 * L432KC GND -- LED-
 * 
 * L432KC D3 -- OSEPPMTD01 ENA
 * L432KC D9 -- OSEPPMTD01 In1
 * L432KC D10 -- OSEPPMTD01 In2
 * L432KC 5V -- OSEPPMTD01 5V
 * L432KC GND -- OSEPPMTD01 GND
 * 
 * Disconnect the jumper JP1 on the MTD-01 !!!!!
 * 12V power -- OSEPPMTD01 VCC
 * 0V power -- OSEPPMTD01 GND
 *
 * MOTOR + -- OSEPPMTD01 OUT1
 * MOTOR - -- OSEPPMTD01 OUT2
 *
 * Operating system OS 6.0
 * Timo Karppinen 3.5.2021  Apache-2.0
 */

#include "mbed.h"

// Speed change every x seconds
#define SpeedChanging_RATE     1s

// Initialise the digital pin D3 as a pwm output
// The pin needs to be one of the PWM capable pins ! 
PwmOut pwmMTD01(D3);
// Variables for the pwm
int spCount = 1;
int spCountStep = 1;
float speed = 1.0;   // from 0.0 to 1.0 
int usT = 1000;   // f = 1000 Hz  T = 1 ms = 1000 us
                    // f = 10000 Hz  T = 100 us
                    
// drive direction for the full bridge driver
DigitalOut in1(D9);
DigitalOut in2(D10);

                  
int main()
{
    pwmMTD01.period_us(usT);
    pwmMTD01.write(0.5f);
    in1.write(false); // forward
    in2.write(true);
    ThisThread::sleep_for(3s); 
    while (true) {
        
        spCount = spCount + spCountStep;
        if(spCount == 25){
            spCountStep = -1;
            }
        if(spCount == 1){
            spCountStep = 1;
            }
        speed = 0.04*(float)spCount;
        pwmMTD01.write(speed);
        
        if(spCount == 1){
            in1.write(!in1.read());
            in2.write(!in2.read());
            }
        
        ThisThread::sleep_for(SpeedChanging_RATE);
    }
}