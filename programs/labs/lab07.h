#include "PwmOut.h"
#include "mbed.h"
#include "crazyflie.h"

AttitudeEstimator attitude_estimator;

int main(){
    attitude_estimator.init();
    while(true){
        attitude_estimator.estimate();

    }
}