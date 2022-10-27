#ifndef parameters_h
#define parameters_h

#include <cmath>

// Physical constants
const float pi = 3.1416;
const float g = 9.81;       // m/s^2

// Quadcopter dimensions
const float m = 30.0e-3;    // kg
const float I_xx = 16.0e-6; // kg.m^2
const float I_yy = 16.0e-6; // kg.m^2
const float I_zz = 29.0e-6; // kg.m^2
const float l = 33.0e-3;    // m

// Valores obtidos
const float a1 = 2.224e-10; // Lab 02
const float a2 = 1.258e-07; // Lab 02
const float kl = 1.313e-08; // Constante de sustentação
const float kd = 9.628e-11; // Lab 04 
const float dt = 0.002;
const float dt_range = 0.050;
const float wc = 1.0;
const float alpha = (wc*dt)/(1.0+wc*dt);
const float Ts = 0.3;
const float OS = 0.002;
const float zetta = abs(log(OS))/(sqrt(log(OS)*log(OS)+pi*pi));
const float wn = 4/(zetta*Ts);
const float kp1 = wn*wn;
const float kd1 = 2*zetta*wn;
const float l1 = wc*wc;
const float l2 = 2*zetta*wc;




#endif