#include "mbed.h"
#include "crazyflie.h"

// Define all LEDs as digital output objects
DigitalOut L1 (LED_BLUE_L,  !false);
DigitalOut L2 (LED_GREEN_L, !false);
DigitalOut L3 (LED_GREEN_R, !false);
DigitalOut L4 (LED_RED_L, !false);
DigitalOut L5 (LED_RED_R, !false);

// Define all motors as PWM objects
PwmOut Motor1 (MOTOR1);
PwmOut Motor2 (MOTOR2);
PwmOut Motor3 (MOTOR3);
PwmOut Motor4 (MOTOR4);


float tempo = 0.0;

// Main program
int main()
{
    // Blink blue LED indicating inicialization (5 seconds)
    while (tempo <= 5.0){
        L1 = !L1;
        wait(0.1);
        tempo += 0.1;
    }
    // Turn on red LEDs indicating motors are armed
    L4 = false;
    L5 = false;
    wait(1);

    // Test all motors with different frequencies (to make different noises)
    Motor1.period(1.0/400.0);
    Motor1 = 0.1;
    wait(1);
    Motor1 = 0.0;

    Motor2.period(1.0/600.0);
    Motor2 = 0.2;
    wait(1);
    Motor2 = 0.0;

    Motor3.period(1.0/800.0);
    Motor3 = 0.3;
    wait(1);
    Motor3 = 0.0;

    Motor4.period(1.0/1000.0);
    Motor4 = 0.4;
    wait(1);
    Motor4 = 0.0;

    // Turn off red LEDs indicating motors are disarmed
    L4 = true;
    L5 = true;

    // Blink green LEDs indicating end of program
    while (true){
        L2 = !L2;
        wait(0.1);
    }
}
