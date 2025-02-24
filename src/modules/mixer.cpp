#include "mixer.h"

 // Class constructor
Mixer::Mixer() : motor_1(MOTOR1), motor_2(MOTOR2), motor_3(MOTOR3), motor_4(MOTOR4), L1(LED_RED_L,!false), L2(LED_RED_R,!false),L3(LED_BLUE_L,!false){

    motor_1.period(1.0/500.0);
    motor_2.period(1.0/500.0);
    motor_3.period(1.0/500.0);
    motor_4.period(1.0/500.0);
    motor_1 = 0.0;
    motor_2 = 0.0;
    motor_3 = 0.0;
    motor_4 = 0.0;


}
// Actuate motors with desired total trust force (N) and torques (N.m)
void Mixer::actuate(float f_t, float tau_phi, float tau_theta, float tau_psi)
{
    mixer(f_t,tau_phi,tau_theta,tau_psi);
    motor_1 = control_motor(omega_1);
    motor_2 = control_motor(omega_2);
    motor_3 = control_motor(omega_3);
    motor_4 = control_motor(omega_4);
} 
// Convert total trust force (N) and torques (N.m) to angular velocities (rad/s)
void Mixer::mixer(float f_t, float tau_phi, float tau_theta, float tau_psi)
{
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

 // Convert desired angular velocity (rad/s) to PWM signal (%)
float Mixer::control_motor(float omega)
{
    float pwm = a2*(omega*omega) + (a1*omega);
    return pwm;
}
void Mixer::arm()
{
    L1 = false;
    L2 = false;
}
void Mixer::disarm(){
    L1 = true;
    L2 = true;
    motor_1 = 0.0;
    motor_2 = 0.0;
    motor_3 = 0.0;
    motor_4 = 0.0;
}