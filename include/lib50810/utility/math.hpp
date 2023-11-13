#pragma once
#include "lib50810/Utility/Units.hpp"
#include "okapi/api/device/motor/abstractMotor.hpp"
#include "okapi/api/chassis/controller/chassisScales.hpp"
#include <cmath>
namespace lib50810
{
    namespace math
    {
        /**
         * @brief Clamps a value into given range. Works for all types.
         * @param val Value to clamp.
         * @param min Minimum value to clamp to.
         * @param max Maximum value to clamp to.
         * @return Clamped value.
        */
        template <typename T> 
        T clamp(T val, T min, T max);
        /**
         * @brief Takes in encoder ticks and converts them into feet.
         * @param ticks Ticks of the chasis.
         * @param wheelRadius Wheel radius of the chassis.
         * @param gearRatio Gear ratio of the chassis.
         * @return Feet traversed of chassis.
        */
        double tickToFt(double tick, okapi::ChassisScales scale, okapi::AbstractMotor::GearsetRatioPair gearset);
        /**
         * @brief Takes in feet and converts them into ticks.
         * @param ft Feet traversed;
         * @param wheelRadius Wheel radius of the chassis.
         * @param gearRatio Gear ratio of the chassis.
         * @return Feet traversed of chassis.
        */
        double ftToTick(double ft, okapi::ChassisScales scale, okapi::AbstractMotor::GearsetRatioPair gearset);
        /**
         * @brief Takes in rpm and converts it into ftps.
         * @param rpm RPM of motor.
         * @param wheelRadius Wheel radius of the chassis.
         * @param gearRatio Gear ratio of the chassis.
         * @return Ftps of chassis.
        */
        double rpmToftps(double rpm, okapi::ChassisScales scale, okapi::AbstractMotor::GearsetRatioPair gearset);
        /**
         * @brief Takes in rpm and converts it into ftps.
         * @param ftps of chassis.
         * @param wheelRadius Wheel radius of the chassis.
         * @param gearRatio Gear ratio of the chassis.
         * @return Ftps of chassis.
        */
        double ftpsTorpm(double ftps, okapi::ChassisScales scale, okapi::AbstractMotor::GearsetRatioPair gearset);

        double angleWrap180(double degree);

    };
};