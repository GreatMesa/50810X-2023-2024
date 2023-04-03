#include "main.h"
#include "Units.hpp"
namespace lib50810
{
    struct MotionLimits
    {
        /**
         * @brief Limits for Motion Profiling
        */
        QSpeed maxVelocity{0.0};
        QAcceleration maxAcceleration{0.0};
        QAcceleration maxDecceleration{0.0};
        QJerk maxJerk{0.0};
        /**
         * @brief Profile Constraint Constructer for S-Curve Profile
         * @param maxVelocity Max velocity (m/s or ft/s)
         * @param maxAcceleration Max acceleration (m/s or ft/s)
         * @param maxDecceleration Max decceleration (m/s^2 or ft/s^2)
         * @param maxJerk Max jerk (m/s^3 or ft/s^3)
        */
        MotionLimits(okapi::QSpeed MaxVel,QAcceleration MaxAccel,QAcceleration maxDecceleration, QJerk MaxJerk);
        MotionLimits(okapi::QSpeed MaxVel,QAcceleration MaxAccel,QJerk MaxJerk);

        ~MotionLimits() = default;
        protected:
        MotionLimits() = default;
        friend class MotionProfile;

    };
};