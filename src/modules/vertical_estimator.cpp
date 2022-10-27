#include "vertical_estimator.h"

// Class Constructor 

VerticalEstimator::VerticalEstimator() : range(E_SDA, E_SCL){
    z = 0.0;
    w = 0.0;
}

void VerticalEstimator::init(){
    range.init();
}

void VerticalEstimator::predict(float f_t){
    w = w + (-g+f_t/m)*dt;
    z = z + w*dt;
}
void VerticalEstimator::correct(float phi, float theta){
    range.read();
    if(range.d < 0.05){
        float z_m = range.d*cos(phi)*cos(theta);
        w = w + l1*dt_range*(z_m - z);
        z = z + l2*dt_range*(z_m - z);
    }
}