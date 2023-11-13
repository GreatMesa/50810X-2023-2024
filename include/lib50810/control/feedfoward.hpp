#pragma once
#include "lib50810/Utility/Math.hpp"
namespace lib50810
{
    struct FFGains
    {
        private:
        double kV, kA, kD,kp_Pos, kp_Vel;
        public:
        FFGains() = default;
        /**
         * @brief Gains for a Feedfoward controller.
         * @param kV kV gain.
         * @param kAcc kA gain.
         * @param kDec kD gain.
         * @param kp_Pos kp gain for position.
         * @param kp_Vel kp gain for velocity.
         */
        FFGains(double kV, double kAcc, double kDec, double kp_Pos, double kp_Vel);
        friend class FFController;

    };  
    class FFController
    {
        private:
        FFGains gains;
        public:
        FFController() = default;
        /**
         * @brief Contructor for feedfoward controller.
         * @param gains Gains for the feedfoward controller.
         */
        FFController(FFGains gains);
        /**
         * @brief Constants for a FeedFoward Position and Velocity controller.
         * @param kV Constant for the kV diff.
         * @param kAcc Constant for the kAcc diff.
         * @param kDec Constant for the kDec diff.
         * @param kp_Pos Constant for the proportional Pos.
         * @param kp_Vel Constant for the proportional Vel.
         */
        FFController(double kV, double kAcc, double kDec, double kp_Pos, double kp_Vel);
        /**
         * @brief Returns the power for a feedfoward position and velocity controller.
         * @param WPos Wanted position of the controller.
         * @param WVel Wanted velocity of the controller.
         * @param WAccel Wanted acceleration of the controller.
         * @param CurPos Current position of the controller.
         * @param CurVel Current velocity of the controller.
         * @return The power calculated in the step.
         */
        double step(double WPos, double WVel, double WAccel, double CurPos, double CurVel);
        /**
         * @brief Returns the power for a feedfoward velocity system.
         * @param WVel Wanted velocity of the controller.
         * @param CurVel Current velocity of the controller.
         * @return The power calculated in the step.
        */
       double step_WVel(double WVel, double CurVel);
    };
}