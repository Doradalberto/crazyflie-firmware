#include "attitude_estimator.h"

AttitudeEstimator::AttitudeEstimator() : imu(IMU_SDA,IMU_SCL){
    phi = 0.0;
    theta = 0.0;
    psi = 0.0;
    p = 0.0;
    q = 0.0;
    r = 0.0;
    p_bias = 0.0;
    q_bias = 0.0;
    r_bias = 0.0;
}

// Initialize class
void AttitudeEstimator::init(){
    imu.init();
    float s = 0;
    float s1 = 0;
    float s2 = 0;

    for(int i = 0; i < 500; i++){
        imu.read();
        s += imu.gx;
        s1 += imu.gy;
        s2 += imu.gz;
        wait(dt);
    }
    p_bias = (1/500)*s;
    q_bias = (1/500)*s;
    r_bias = (1/500)*s;

}

// Estimate Euler angles (rad) and angular velocities (rad/s)
void AttitudeEstimator::estimate(){
    imu.read();
    
    p = imu.gx - p_bias;  // Giroscopio 
    q = imu.gx -  q_bias;
    r = imu.gz - r_bias;

    float phi_a = atan2(-imu.ay,-imu.az); // Acelerometro 
    // float phi_g = phi + p*dt; // Linear
    float phi_g = phi + (p+sin(phi)*tan(theta)*q+cos(phi)*tan(theta)*r)*dt; // Não Linear
    phi = (1-alpha)*phi_g + alpha*phi_a; 

    // float theta_a = atan2(imu.ax,-imu.az); // Linear
    float theta_a = atan2(imu.ax,imu.ax/(-signbit(imu.az)*sqrt(imu.ay*imu.ay+imu.az*imu.az))); // Não linear
    // float theta_g = theta + q*dt; // Linear
    float theta_g = theta + (cos(phi)*q-sin(phi)*r)*dt;
    theta = (1-alpha)*theta_g + alpha*theta_a;

    // psi = psi + r * dt; // Linear
    psi = psi +(sin(phi)*(1/cos(theta))*q+cos(phi)*(1/cos(theta))*r)*dt;

}
