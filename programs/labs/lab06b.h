#include "mbed.h"
#include "crazyflie.h"

Mixer mixer;

int main(){
    mixer.arm();
    mixer.actuate(0.0, 0.0, 0.0, -0.001);
    wait(5);
    mixer.actuate(0.0, 0.0, 0.0, 0.0);
    while(true){
        mixer.disarm();
    }
}