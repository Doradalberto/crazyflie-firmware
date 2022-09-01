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

float control_motor(float omega) {
    float pwm = a2*(omega*omega) + (a1*omega);
    return pwm;
}

// Main program
int main() {
    while(true) {
        L4 = false;
        Motor1.period(1.0/500.0);
        Motor1 = control_motor(1000.0);
        Motor2.period(1.0/500.0);
        Motor2 = control_motor(2000.0);
        Motor3.period(1.0/500.0);
        Motor3 = control_motor(1000.0);
        Motor4.period(1.0/500.0);
        Motor4 = control_motor(2000.0);
        wait(2);
        Motor1 = 0.0;
        Motor2 = 0.0;
        Motor3 = 0.0;
        Motor4 = 0.0;
        wait(5);
    }
}
