#ifndef parameters_h
#define parameters_h

#include <cmath>

// Physical constants
const float pi = 3.1415;
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

// Ganho estimador de atitude
const float omega_C = 1.0;
const float alpha = (omega_C*dt)/(1.0+omega_C*dt);

// Ganho controlador de atitude
const float UP = 0.005;
const float Ts = 0.3;
const float zetta = abs(log(UP))/sqrt(pi*pi+log(UP)*log(UP));
const float wn = 4.0/(zetta*Ts);
const float kp_att = wn*wn;
const float kd_att = 2.0*zetta*wn;

const float Ts_psi = 0.5;
const float wn_psi = 4.0/(zetta*Ts_psi);
const float kp_att_psi = wn_psi*wn_psi;
const float kd_att_psi = 2.0*zetta*wn_psi;

// Ganho estimador vertical
const float w_c = 10.0;
const float zetta_vert = sqrt(2.0)/2.0;
const float l1 = w_c*w_c;
const float l2 = w_c*2*zetta_vert;

// Ganho controlador vertical
const float kp_cv = 5.8567;
const float kd_cv = 3.4225;

// Estimador Horizontal
const float angulo_visao_gamma = 42.0*(pi/180.0);
const float resolucao_W = 420.0;
const float sigma = (2.0*tan(angulo_visao_gamma/2.0))/(resolucao_W*dt);

const float l1_horizontal = 50.0;

// Controlador horizontal 
const float OS_Horizontal = 0.005;
const float Ts_Horizontal = 2.0;
const float zetta_hor= abs(log(OS_Horizontal))/sqrt(pi*pi+log(OS_Horizontal)*log(OS_Horizontal));

const float wn_hor = 4.0/(zetta_hor*Ts_Horizontal);
const float kp_hor = wn_hor*wn_hor;
const float kd_hor = 2.0*zetta_hor*wn_hor;
#endif