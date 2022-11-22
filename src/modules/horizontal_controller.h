# ifndef horizontal_controller_h
# define horizontal_controller_h

# include "mbed.h"
# include "crazyflie.h"

// Horizontal estimator class
class HorizontalController
{
    public :
    // Class constructor
        HorizontalController () ;
    // Initialize class
        void control(float x_r,float y_r,float x, float y, float u, float v);
    // Horizontal positions (m) and velocities (m/s) estimations
        float phi_r, theta_r;
    private :
    // Flow sensor object
        float control_siso(float pos_r, float pos, float vel, float kp, float kd);
};

# endif