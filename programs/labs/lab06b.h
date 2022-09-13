#include "mbed.h"
#include "crazyflie.h"

Mixer mixer;

int main(){
    mixer.arm(true);
    mixer.actuate(0.0, 0.0, 0.0, -0.001);
    wait(5);
    mixer.actuate(0.0, 0.0, 0.0, 0.0);
    mixer.arm(false);
}