#include "mbed.h"
#include "crazyflie.h"
#include <cmath>

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

float omega_1;
float omega_2;
float omega_3;
float omega_4;

float control_motor(float omega) {
    float pwm = a2*(omega*omega) + (a1*omega);
    return pwm;
}

void mixer(float f_t, float tau_phi, float tau_theta, float tau_psi) {
    omega_1 = f_t/(4*kl) - tau_psi/(4*kd) - tau_phi/(4*kl*l) - tau_theta/(4*kl*l);
    omega_2 = f_t/(4*kl) + tau_psi/(4*kd) - tau_phi/(4*kl*l) + tau_theta/(4*kl*l);
    omega_3 = f_t/(4*kl) - tau_psi/(4*kd) + tau_phi/(4*kl*l) + tau_theta/(4*kl*l);
    omega_4 = f_t/(4*kl) + tau_psi/(4*kd) + tau_phi/(4*kl*l) - tau_theta/(4*kl*l);
    if(omega_1 < 0){
        omega_1 = 0;
    } else { omega_1 = sqrt(omega_1);}

    if(omega_2 < 0){
        omega_2 = 0;
    } else { omega_2 = sqrt(omega_2);}

    if(omega_3 < 0){
        omega_3 = 0;
    } else { omega_3 = sqrt(omega_3);}

    if(omega_4 < 0){
        omega_4 = 0;
    } else { omega_4 = sqrt(omega_4);}

}
void actuate(float f_t, float tau_phi, float tau_theta, float tau_psi){
    mixer(f_t,tau_phi,tau_theta,tau_psi);
    Motor1 = control_motor(omega_1);
    Motor2 = control_motor(omega_2);
    Motor3 = control_motor(omega_3);
    Motor4 = control_motor(omega_4);

}
// Main program
int main() {
    L4 = false;
    Motor1.period(1.0/500.0);
    Motor2.period(1.0/500.0);
    Motor3.period(1.0/500.0);
    Motor4.period(1.0/500.0);

    actuate(0.2,0,0,0);
    wait(5);
    actuate(0,0,0,0);
}
