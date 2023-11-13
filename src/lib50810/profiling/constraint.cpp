#include "lib50810/profiling/constraint.hpp"
namespace lib50810
{
    ChassisConstraint::ChassisConstraint(okapi::QSpeed mv, okapi::QAcceleration ma, okapi::QAcceleration md)
    {
        this->maxVelocity = mv;
        this->maxAcceleration = ma;
        this->maxDecceleration = md;
    }
}