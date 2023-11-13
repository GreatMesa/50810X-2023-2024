#include "lib50810/profiling/profilepoint.hpp"
namespace lib50810
{
    profilePoint::profilePoint(double leftpos, double rightpos, double leftvel, double rightvel, double leftaccel, double rightaccel)
    {
        this->leftpos = leftpos;
        this->rightpos = rightpos;
        this->leftvel = leftvel;
        this->rightvel = rightvel;
        this->leftaccel = leftaccel;
        this->rightaccel = rightaccel;
    }
    profilePoint::profilePoint(double pos, double vel, double accel)
    {
        this->leftpos = pos;
        this->rightpos = pos;
        this->leftvel = vel;
        this->rightvel = vel;
        this->leftaccel = accel;
        this->rightaccel = accel;
    }
}