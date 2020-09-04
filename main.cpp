/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 *********************************************
 *
 * PWM example using the PwmOut API
 *
 *********************************************
 *Description: McLab12_MOSFET_PWM_OS6_tk1
 * Hardware
 * L432KC or similar with PWM capable outputs.
 * The L432KC pin D13 for onboard LED is not PWM capable!
 * LED and 220 Ohm resistor
 * For testing MOSFET: IRL540 + protection diode + DC motor
 * Connect:
 * L432KC D10 -- 220 Ohm -- LED+ 
 * L432KC GND -- LED-
 * or
 * L432KC D10 -- MOSFET gate
 *
 * Operating system OS 6.0
 * Timo Karppinen 4.9.2020  Apache-2.0
 */

#include "mbed.h"

// Speed change every x seconds
#define SpeedChanging_RATE     1s

// Initialise the digital pin D10 as a pwm output
// The pin needs to be one of the PWM capable pins ! 
PwmOut pwmMOSFET(D10);
// Variables for the pwm
int spCount = 1;
float speed = 1.0;   // from 0.0 to 1.0 
float usT = 1000;   // f = 1000 Hz  T = 1 ms = 1000 us
                    // f = 10000 Hz  T = 100 us
int main()
{
    pwmMOSFET.period_us(usT);
    pwmMOSFET.write(1.0f);
    while (true) {
        
        spCount = spCount + 1;
        if(spCount == 25){
            spCount = 1;
            }
        speed = 1/(float)spCount;
        pwmMOSFET.write(speed);
        
        ThisThread::sleep_for(SpeedChanging_RATE);
    }
}