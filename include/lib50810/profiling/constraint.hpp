#pragma once
#include "lib50810/utility/Units.hpp"
namespace lib50810
{
    struct ChassisConstraint
    {
        private:
        okapi::QSpeed maxVelocity;
        okapi::QAcceleration maxAcceleration;
        okapi::QAcceleration maxDecceleration;
        public:
        /**
         * @brief Constructor for a chasiss constraint.
         * @param mv Max veclocity of chassis.
         * @param ma Max acceleration of chassis.
         * @param md Max decceleration of chassis.
        */
        ChassisConstraint(okapi::QSpeed mv, okapi::QAcceleration ma, okapi::QAcceleration md);

        ChassisConstraint() = default;
        friend class trapezoidalProfile;
    };
}