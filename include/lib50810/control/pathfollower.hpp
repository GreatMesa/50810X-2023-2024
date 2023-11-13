#pragma once
#include "lib50810/profiling/trapezoidal.hpp"
#include "lib50810/utility/math.hpp"
#include "lib50810/control/feedfoward.hpp"
#include "okapi/api/chassis/controller/chassisController.hpp"
#include "okapi/api/chassis/model/skidSteerModel.hpp"
#include "okapi/api/device/motor/abstractMotor.hpp"
namespace lib50810
{
    class pathFollower
    {
        private:
        FFController ff;
        std::shared_ptr<okapi::ChassisController> chassis;
        std::shared_ptr<okapi::AbstractMotor> leftMotor;
        std::shared_ptr<okapi::AbstractMotor> rightMotor;
        trapezoidalProfile profile;
        public:
        /**
         * @brief Creates a path follower object.
         * @param ichassis Robot chassis.
         * @param iprofile Trapezoidal Profile.
         * @param ifeedfoward Feedfoward Controller.
        */
        pathFollower(std::shared_ptr<okapi::ChassisController> ichassis,
                     trapezoidalProfile iprofile,
                     FFController ifeedfoward);
        void move(okapi::QLength distance);
        void turn(okapi::QAngle angle);
    };
}