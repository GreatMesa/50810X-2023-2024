#include "feedfoward.hpp"
namespace lib50810
{
    FFController::FFController(FFGains gains)
    {
        this->gains = gains;
    }
    FFController::FFController(double kV, double kAcc, double kDec, double kp_Pos, double kp_Vel)
    {
        this->gains.kV = kV;
        this->gains.kA = kAcc;
        this->gains.kD = kAcc;
        this->gains.kp_Pos = kp_Pos;
        this->gains.kp_Vel = kp_Vel;
    }
    double FFController::step(double WPos, double WVel, double WAccel, double CurPos, double CurVel)
    {
        if(WAccel > 0)
        {
            return ((gains.kV * WVel) + (gains.kA * WAccel) + gains.kp_Pos * (WPos - CurPos) + gains.kp_Vel * (WVel - CurVel));
        }
        else
        {
            return ((gains.kV * WVel) + (gains.kD * WAccel) + gains.kp_Pos * (WPos - CurPos) + gains.kp_Vel * (WVel - CurVel));
        }
    }
    double FFController::step_WVel(double WVel, double CurVel)
    {    
        return ((gains.kV * WVel) + gains.kp_Vel * (WVel - CurVel));
    }
    
}