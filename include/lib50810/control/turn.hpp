#pragma once
#include "okapi/impl/device/rotarysensor/IMU.hpp"
#include "okapi/api/chassis/controller/chassisController.hpp"
#include "okapi/api/chassis/model/skidSteerModel.hpp"
#include "lib50810/utility/Units.hpp"
#include "lib50810/utility/Math.hpp"
#include <memory>
#include <functional>
namespace lib50810 
{
    class turnPID
    {
        private:
        std::shared_ptr<okapi::IMU> imu; // IMU
        std::shared_ptr<okapi::AbstractMotor> left; // Left-Side MotorGroup
        std::shared_ptr<okapi::AbstractMotor> right; // Right-Side MotorGroup
        //Constants
        double kp; // Proportional Constant.
        double ki; // Integral Constant.
        double kd; // Derivative Constant.
        double merror; //Max error allowed for loop stop.
        //Error variables.
        double error{0}; // Error of pid controller.
        double lastError{0}; // Previous Error of pid controller.
        double maxTime;
        double power{0};
        bool ifSettled;
        public:
        /**
         * @brief Construct a Turn-PID object.
         * @param Imu Imu used in calculating heading.
         * @param ichassis Chassis used in turning.
         * @param imerror Max error for settled loop.
         * @param itime Max time for the pid loop.
         * @param ikp Proportional constant.
         * @param iki Integral constant.
         * @param ikd Derivative constant.
        */
        turnPID(std::shared_ptr<okapi::IMU> Imu,
                std::shared_ptr<okapi::ChassisController> chassis,
                double imerror,
                double itime,
                double ikp,
                double iki,
                double ikd);
        /**
         * @brief Make a step for the turn PID
         * @param ierror Error of the pid controller.
         * @param iprevError Previous Error of the pid controller.
         * @param min Minimum power limit.
         * @param max Maximum power limit.
         * @return Power for the motors.
        */
        double step(double ierror, double iprevError, double min, double max);
        /**
         * @brief Returns the amount of error.
         * @return Error.
        */
        double getError();
        /**
         * @brief Make a turn of given digrees.
         * @param iangle Angle you want to turn.
        */
        void turn(okapi::QAngle iangle);
        /**
         * @brief Makes a turn, executes a function, than turns back.
         * @param iangle Angle you want to turn.
         * @param function Function you want to execute.
        */
        void turnExec(okapi::QAngle iangle,std::function<void()> function);
    };
}