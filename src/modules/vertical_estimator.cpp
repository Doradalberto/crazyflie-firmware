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
    range.read();
    z = (1-alpha)*z + alpha*z;
}

void VerticalEstimator::correct(float phi, float theta){
    range.read();
    if(range.d < 2.0){
        float z_m = range.d*cos(phi)*cos(theta);
        z = z_m;
    }
}