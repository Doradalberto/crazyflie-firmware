#include "mbed.h" 
#include "crazyflie.h" 
#include "USBSerial.h"

// Define serial object
USBSerial serial;
// Define Callback functions
char command;
// Define serial command variable
AttitudeEstimator att_est;
// Define Ticker objects
Ticker tic;
bool flag;

void  callback(){
    flag = true;
}

int main(){
    att_est.init(); // inicializando
    tic.attach(&callback, dt);
    while(true){
        if(flag){
            flag = false;
            att_est.estimate();
        }
        if(serial.readable()){
            command = serial.getc();
            if(command == 'p'){
                serial.printf("%f,%f,%f\n",att_est.phi,att_est.theta,att_est.psi);
            }
        }
    }

}