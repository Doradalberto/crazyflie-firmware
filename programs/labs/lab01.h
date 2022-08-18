#include "mbed.h"
#include "crazyflie.h"

// Define all LEDs as digital output objects
DigitalOut L1 (LED_BLUE_L,  !false);
DigitalOut L2 (LED_GREEN_L, !false);
DigitalOut L3 (LED_GREEN_R, !false);
DigitalOut L4 (LED_RED_L, !false);
DigitalOut L5 (LED_RED_R, !false);

// Define all motors as PWM objects
PwmOut M1 (MOTOR1);
PwmOut M2 (MOTOR2);
PwmOut M3 (MOTOR3);
PwmOut M4 (MOTOR4);

float tempo = 0.0;

// Main program
int main()
{
    // Blink blue LED indicating inicialization (5 seconds)
    
    // Turn on red LEDs indicating motors are armed
    
    // Test all motors with different frequencies (to make different noises)
    
    // Turn off red LEDs indicating motors are disarmed
    
    // Blink green LEDs indicating end of program

    while (tempo <= 5.0){
        L1 != L1;
        wait(0.1);
        tempo += 0.1;
    }

    while(true)
    {
        //L3 = false;
        //L4 = false;
        //L5 = false;

        
    }
}
